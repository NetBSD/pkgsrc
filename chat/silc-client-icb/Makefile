# $NetBSD: Makefile,v 1.21 2012/10/03 00:02:44 asau Exp $
#

DISTNAME=	irssi-icb-0.14
PKGNAME=	${DISTNAME:S/irssi/silc-client/}
PKGREVISION=	14
CATEGORIES=	chat
MASTER_SITES=	http://www.irssi.org/files/plugins/icb/
DISTFILES=	${DISTNAME}.tar.gz ${SILC_CLIENT_DISTFILE}

MAINTAINER=	salo@NetBSD.org
HOMEPAGE=	http://www.silcnet.org/
COMMENT=	silc-client plugin to access ICB networks

DEPENDS+=	silc-client>=${SILC_CLIENT_VERSION}:../../chat/silc-client

.include "../../chat/silc-client/Makefile.common"

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes

IRSSI_DIR=	${WRKDIR}/${SILC_CLIENT_DISTNAME}/apps/irssi

CONFIGURE_ARGS+=	--with-irssi=${IRSSI_DIR:Q}

INSTALLATION_DIRS+=	share/doc/silc-client

post-extract:
	${CP} ${SILC_CLIENT_CONFIG_H} ${IRSSI_DIR}/config.h
	${CP} ${SILC_CLIENT_CONFIG} ${IRSSI_DIR}/irssi-config

post-install:
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/silc-client/README.icb

.include "../../devel/glib/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
