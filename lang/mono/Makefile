# $NetBSD: Makefile,v 1.30 2004/10/03 00:15:01 tv Exp $
#

DISTNAME=	mono-1.0.1
PKGREVISION=	1
CATEGORIES=	lang
MASTER_SITES=	http://www.go-mono.com/archive/1.0.1/

MAINTAINER=	recht@NetBSD.org
HOMEPAGE=	http://www.mono-project.com/
COMMENT=	Open source implementation of the .NET Development Framework

#BUILD_DEPENDS+=	p5-XML-Parser-[0-9]*:../../textproc/p5-XML-Parser

CONFLICTS=	pnet-[0-9]*

# XXX please test
NOT_FOR_PLATFORM=	NetBSD-1.[0-5]*-*
NOT_FOR_PLATFORM+=	NetBSD-1.6-* NetBSD-1.6.*-*
NOT_FOR_PLATFORM+=	NetBSD-1.6[A-Z]-* NetBSD-1.6Z[AB]-*

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

.include "../../mk/bsd.prefs.mk"

# mcs coredumps with sigaltstack
.if ${OPSYS} == "NetBSD"
CONFIGURE_ARGS+=	--with-sigaltstack=no
.endif

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../textproc/icu/buildlink3.mk"

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
