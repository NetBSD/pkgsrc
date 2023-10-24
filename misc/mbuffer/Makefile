# $NetBSD: Makefile,v 1.9 2023/10/24 22:10:03 wiz Exp $

DISTNAME=	mbuffer-20180625
PKGREVISION=	2
CATEGORIES=	misc
MASTER_SITES=	http://www.maier-komor.de/software/mbuffer/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.maier-komor.de/mbuffer.html
COMMENT=	Tool for buffering data streams
LICENSE=	gnu-gpl-v3

BROKEN_ON_PLATFORM=	NetBSD-*-*	# Needs sysctl bits

GNU_CONFIGURE=	yes

USE_LANGUAGES=	c c99

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

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
