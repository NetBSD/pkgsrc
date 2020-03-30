# $NetBSD: Makefile,v 1.8 2020/03/30 19:02:32 jperkin Exp $

DISTNAME=	mbuffer-20180625
PKGREVISION=	1
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
