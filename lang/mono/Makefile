# $NetBSD: Makefile,v 1.27 2004/07/03 23:02:50 recht Exp $
#

DISTNAME=	mono-1.0
CATEGORIES=	lang
MASTER_SITES=	http://mono2.ximian.com/archive/1.0/

MAINTAINER=	recht@NetBSD.org
HOMEPAGE=	http://www.mono-project.com/
COMMENT=	Open source implementation of the .NET Development Framework

#BUILD_DEPENDS+=	p5-XML-Parser-[0-9]*:../../textproc/p5-XML-Parser

CONFLICTS=	pnet-[0-9]*

# XXX please test
NOT_FOR_PLATFORM=	NetBSD-1.[0-5]*-*
NOT_FOR_PLATFORM+=	NetBSD-1.6-* NetBSD-1.6.*-*
NOT_FOR_PLATFORM+=	NetBSD-1.6[A-Z]-* NetBSD-1.6Z[AB]-*
# boehm-gc doesn't build on amd64/x86_64
NOT_FOR_PLATFORM+=	FreeBSD-*-amd64 FreeBSD-*-x86_64

USE_GNU_TOOLS+=		make yacc
USE_BUILDLINK3=		yes
USE_PKGINSTALL=		yes
USE_LIBTOOL=		yes

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-preview=yes
CONFIGURE_ARGS+=	--with-ikvm-jni=no
CONFIGURE_ARGS+=	--with-jdk=no
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}

MAKE_FLAGS+=		PERL=${PERL5}

PKGCONFIG_OVERRIDE=	mint.pc.in
PKGCONFIG_OVERRIDE=	mono.pc.in
PKG_SYSCONFSUBDIR=	mono

USE_PERL5=	build
REPLACE_PERL=	mono/cil/make-opcodes-def.pl
REPLACE_PERL+=	mono/metadata/make-bundle.pl
REPLACE_PERL+=	mono/mini/build_relations_propagation_table.pl
REPLACE_PERL+=	mono/benchmark/test-driver
REPLACE_PERL+=	mono/tests/test-driver

EGDIR=		${PREFIX}/share/examples/mono
CONF_FILES=	${EGDIR}/config ${PKG_SYSCONFDIR}/config
CONF_FILES+=	${EGDIR}/browscap.ini ${PKG_SYSCONFDIR}/browscap.ini
CONF_FILES+=	${EGDIR}/machine.config ${PKG_SYSCONFDIR}/machine.config
CONF_FILES+=	${EGDIR}/DefaultWsdlHelpGenerator.aspx \
		${PKG_SYSCONFDIR}/DefaultWsdlHelpGenerator.aspx

#DEINSTALL_EXTRA_TMPL=	${PKGDIR}/DEINSTALL

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Linux"
.  if defined(MONO_USE_NPTL) && !empty(MONO_USE_NPTL:M[yY][eE][sS])
# Enable support for NPTL
CONFIGURE_ARGS+=	--with-nptl=yes
.  endif
BUILD_DEFS+=	MONO_USE_NPTL
.else
CONFIGURE_ARGS+=	--with-nptl=no
.endif

# allow changing the gc_type
# allowed values: included, boehm, none
MONO_GC_TYPE?=included
.if ${MONO_GC_TYPE} == "boehm"
.  include "../../devel/boehm-gc/buildlink3.mk"
.endif
CONFIGURE_ARGS+=	--with-gc=${MONO_GC_TYPE}

# mono debugger support is only available with the included gc
# patch the PLIST accordingly
.if ${MONO_GC_TYPE} == "boehm" || ${MONO_GC_TYPE} == "none"
PLIST_SUBST+=  GC="@comment "
.else
PLIST_SUBST+=  GC=
.endif

# mcs coredumps with sigaltstack
.if ${OPSYS} == "NetBSD"
CONFIGURE_ARGS+=	--with-sigaltstack=no
.endif

# Global Assembly Cache files are handled during (de)installation.
#PRINT_PLIST_AWK+=	/^lib\/mono\/gac\// { next; }
#PRINT_PLIST_AWK+=	/^@dirrm lib\/mono\/gac\// { next; }

# GC files are only installed if GC was enabled.
PRINT_PLIST_AWK+=	/^include\/mono\/private\/libgc/ \
				{ print "$${GC}" $$0; next; }
PRINT_PLIST_AWK+=	/^@dirrm include\/mono\/private/ \
				{ print "$${GC}" $$0; next; }

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../textproc/icu/buildlink3.mk"

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
