# $NetBSD: Makefile,v 1.7 2004/01/20 12:09:35 agc Exp $
#

DISTNAME=	irssi-icb-0.14
PKGREVISION=	3
CATEGORIES=	chat
MASTER_SITES=	http://www.irssi.org/files/plugins/icb/
DISTFILES=	${DISTNAME}.tar.gz ${IRSSI_DISTFILE}

MAINTAINER=	jmmv@NetBSD.org
HOMEPAGE=	http://www.irssi.org/
COMMENT=	Irssi plugin to access ICB networks

WRKSRC=		${WRKDIR}/${IRSSI_DISTNAME}/${DISTNAME}

.include "${.CURDIR}/../../chat/irssi/Makefile.common"

DEPENDS+=	irssi>=${IRSSI_VERSION}:../../chat/irssi

USE_BUILDLINK2=	yes
GNU_CONFIGURE=	yes

USE_LIBTOOL=	yes
SHLIBTOOL_OVERRIDE=	${WRKSRC}/libtool

CONFIGURE_ARGS+=	--with-irssi=${WRKDIR}/${IRSSI_DISTNAME}

post-extract:
	${MV} ${WRKDIR}/${DISTNAME} ${WRKDIR}/${IRSSI_DISTNAME}
	${CP} ${IRSSI_CONFIG_H} ${WRKDIR}/${IRSSI_DISTNAME}/config.h
	${CP} ${IRSSI_CONFIG} ${WRKDIR}/${IRSSI_DISTNAME}/irssi-config

post-install:
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/irssi/README.icb

.include "../../devel/glib/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
