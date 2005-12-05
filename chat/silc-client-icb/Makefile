# $NetBSD: Makefile,v 1.16 2005/12/05 20:49:54 rillig Exp $
#

DISTNAME=	irssi-icb-0.14
PKGNAME=	${DISTNAME:S/irssi/silc-client/}
PKGREVISION=	11
CATEGORIES=	chat
MASTER_SITES=	http://www.irssi.org/files/plugins/icb/
DISTFILES=	${DISTNAME}.tar.gz ${SILC_CLIENT_DISTFILE}

MAINTAINER=	salo@NetBSD.org
HOMEPAGE=	http://www.silcnet.org/
COMMENT=	silc-client plugin to access ICB networks

DEPENDS+=	silc-client>=${SILC_CLIENT_VERSION}:../../chat/silc-client

.include "../../chat/silc-client/Makefile.common"

GNU_CONFIGURE=	YES

IRSSI_DIR=	${WRKDIR}/${SILC_CLIENT_DISTNAME}/irssi

CONFIGURE_ARGS+=	--with-irssi=${IRSSI_DIR:Q}

post-extract:
	${CP} ${SILC_CLIENT_CONFIG_H} ${IRSSI_DIR}/config.h
	${CP} ${SILC_CLIENT_CONFIG} ${IRSSI_DIR}/irssi-config

post-install:
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/silc-client/README.icb

.include "../../devel/glib/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
