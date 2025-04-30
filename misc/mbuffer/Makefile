# $NetBSD: Makefile,v 1.11 2025/04/30 13:10:04 hauke Exp $

DISTNAME=	mbuffer-20250429
CATEGORIES=	misc
MASTER_SITES=	http://www.maier-komor.de/software/mbuffer/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.maier-komor.de/mbuffer.html
COMMENT=	Tool for buffering data streams
LICENSE=	gnu-gpl-v3

USE_LANGUAGES=		c
USE_CC_FEATURES=	c99
USE_TOOLS+=		gmake

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}

SUBST_CLASSES+=		etc
SUBST_STAGE.etc=	pre-configure
SUBST_FILES.etc=	mbuffer.rc
SUBST_MESSAGE.etc=	Fix default sysconfdir
SUBST_VARS.etc+=	PKG_SYSCONFDIR

INSTALL_MAKE_FLAGS+=	etcdir=${PREFIX}/share/examples/mbuffer
INSTALLATION_DIRS+=	share/examples/mbuffer
CONF_FILES+=		share/examples/mbuffer/mbuffer.rc \
			${PKG_SYSCONFDIR}/mbuffer.rc

CHECK_PORTABILITY_SKIP+=	configure.in

TEST_TARGET=		test0 test1 test2 test3 test4 test5 test6 test7

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
