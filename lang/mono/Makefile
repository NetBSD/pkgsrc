# $NetBSD: Makefile,v 1.43 2005/12/05 20:50:26 rillig Exp $

DISTNAME=	mono-1.1.8.3
PKGREVISION=	1
CATEGORIES=	lang
MASTER_SITES=	http://go-mono.com/sources/mono-1.1/

MAINTAINER=	recht@NetBSD.org
HOMEPAGE=	http://www.mono-project.com/
COMMENT=	Open source implementation of the .NET Development Framework

BUILD_DEPENDS+=	p5-XML-Parser-[0-9]*:../../textproc/p5-XML-Parser

CONFLICTS=	pnet-[0-9]*

# XXX please test
NOT_FOR_PLATFORM=	NetBSD-1.[0-5]*-*
NOT_FOR_PLATFORM+=	NetBSD-1.6-* NetBSD-1.6.*-*
NOT_FOR_PLATFORM+=	NetBSD-1.6[A-Z]-* NetBSD-1.6Z[AB]-*

# LP64 problems
NOT_FOR_PLATFORM+=	*-*-alpha *-*-sparc64

USE_TOOLS+=		bison gmake gtar perl:run pkg-config
USE_PKGINSTALL=		yes
USE_LIBTOOL=		yes
EXTRACT_USING=		gtar

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}

MAKE_FLAGS+=		PERL=${PERL5:Q}
UNLIMIT_RESOURCES=	datasize
UNLIMIT_RESOURCES+=	stacksize
UNLIMIT_RESOURCES+=	memorysize

PKGCONFIG_OVERRIDE=	mint.pc.in
PKGCONFIG_OVERRIDE+=	mono.pc.in
PKGCONFIG_OVERRIDE+=	scripts/mono-nunit.pc.in
#PKG_SYSCONFSUBDIR=	mono

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

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../textproc/icu/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../textproc/libxslt/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
