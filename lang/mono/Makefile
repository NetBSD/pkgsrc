# $NetBSD: Makefile,v 1.34 2005/04/04 07:22:34 recht Exp $

DISTNAME=	mono-1.1.6
CATEGORIES=	lang
MASTER_SITES=	http://www.go-mono.com/archive/1.1.6/

MAINTAINER=	recht@NetBSD.org
HOMEPAGE=	http://www.mono-project.com/
COMMENT=	Open source implementation of the .NET Development Framework

BUILD_DEPENDS+=	p5-XML-Parser-[0-9]*:../../textproc/p5-XML-Parser

CONFLICTS=	pnet-[0-9]*

# XXX please test
NOT_FOR_PLATFORM=	NetBSD-1.[0-5]*-*
NOT_FOR_PLATFORM+=	NetBSD-1.6-* NetBSD-1.6.*-*
NOT_FOR_PLATFORM+=	NetBSD-1.6[A-Z]-* NetBSD-1.6Z[AB]-*
# XXX currently broken on -3/-current
NOT_FOR_PLATFORM+=	NetBSD-2.9*-* NetBSD-3.*-*

# LP64 problems
NOT_FOR_PLATFORM+=	*-*-alpha *-*-sparc64

USE_GNU_TOOLS+=		make yacc
USE_BUILDLINK3=		yes
USE_PKGINSTALL=		yes
USE_LIBTOOL=		yes

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-ikvm-native=no
CONFIGURE_ARGS+=	--with-icu=yes
CONFIGURE_ARGS+=	--with-jit=yes
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}

MAKE_FLAGS+=		PERL=${PERL5}
UNLIMIT_RESOURCES=	datasize
UNLIMIT_RESOURCES+=	stacksize
UNLIMIT_RESOURCES.=	memorysize

PKGCONFIG_OVERRIDE=	mint.pc.in
PKGCONFIG_OVERRIDE+=	mono.pc.in
PKGCONFIG_OVERRIDE+=	scripts/mono-nunit.pc.in
#PKG_SYSCONFSUBDIR=	mono

USE_PERL5=	build
REPLACE_PERL=	mcs/errors/do-tests.pl
REPLACE_PERL+=	mcs/mbas/Test/test-mbas.pl
REPLACE_PERL+=	mcs/tools/scan-tests.pl
REPLACE_PERL+=	mono/benchmark/test-driver
REPLACE_PERL+=	mono/cil/make-opcodes-def.pl
REPLACE_PERL+=	mono/metadata/make-bundle.pl
REPLACE_PERL+=	mono/tests/stress-runner.pl

EGDIR=		${PREFIX}/share/examples/mono
CONF_FILES=	${EGDIR}/config ${PKG_SYSCONFDIR}/mono/config
CONF_FILES+=	${EGDIR}/browscap.ini ${PKG_SYSCONFDIR}/mono/browscap.ini
#CONF_FILES+=	${EGDIR}/machine.config ${PKG_SYSCONFDIR}/machine.config
#CONF_FILES+=	${EGDIR}/DefaultWsdlHelpGenerator.aspx \
#		${PKG_SYSCONFDIR}/DefaultWsdlHelpGenerator.aspx

TEST_TARGET=	check

.include "../../mk/bsd.prefs.mk"

# mcs coredumps with sigaltstack
.if ${OPSYS} == "NetBSD"
CONFIGURE_ARGS+=	--with-sigaltstack=no
.endif

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../textproc/icu/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../textproc/libxslt/buildlink3.mk"

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
