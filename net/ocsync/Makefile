# $NetBSD: Makefile,v 1.34 2024/05/29 16:34:00 adam Exp $

DISTNAME=	ocsync-0.90.4
PKGREVISION=	32
CATEGORIES=	net
MASTER_SITES=	http://download.owncloud.com/desktop/stable/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://owncloud.org/sync-clients/
COMMENT=	File synchronization program for OwnCloud
LICENSE=	gnu-gpl-v2

EXTRACT_USING=	bsdtar

USE_LANGUAGES=	c c++

USE_CMAKE=	yes
OBJDIR=		../build
CONFIGURE_DIRS=	${OBJDIR}
CMAKE_ARG_PATH=	../${DISTNAME}

EGDIR=		${PREFIX}/share/examples/ocsync
CONF_FILES+=	${EGDIR}/ocsync.conf.default ${PKG_SYSCONFDIR}/ocsync.conf
CONF_FILES+=	${EGDIR}/ocsync_exclude.conf.default \
		${PKG_SYSCONFDIR}/ocsync_exclude.conf

pre-configure:
	cd ${WRKSRC} && mkdir ${OBJDIR}
	cd ${WRKSRC}/config && ${CP} ocsync.conf ocsync.conf.default
	cd ${WRKSRC}/config && ${CP} ocsync_exclude.conf \
		ocsync_exclude.conf.default

.include "../../databases/sqlite3/buildlink3.mk"
.include "../../devel/iniparser/buildlink3.mk"
.include "../../security/libssh/buildlink3.mk"
.include "../../www/neon/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
