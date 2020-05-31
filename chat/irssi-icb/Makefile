# $NetBSD: Makefile,v 1.46 2020/05/31 15:10:11 rillig Exp $
#

DISTNAME=	irssi-icb-0.15
PKGREVISION=	6
CATEGORIES=	chat
MASTER_SITES=	https://github.com/downloads/jperkin/irssi-icb/
DISTFILES=	${DISTNAME}.tar.gz ${IRSSI_DISTFILE}

MAINTAINER=	jperkin@joyent.com
HOMEPAGE=	http://www.irssi.org/
COMMENT=	Irssi plugin to access ICB networks
LICENSE=	gnu-gpl-v2

.include "../../mk/bsd.prefs.mk"
.include "../../chat/irssi/Makefile.common"

WRKSRC=		${WRKDIR}/${IRSSI_DISTNAME}/${DISTNAME}

DEPENDS+=	irssi>=${IRSSI_VERSION}:../../chat/irssi

GNU_CONFIGURE=	yes

USE_LIBTOOL=		yes
USE_TOOLS+=		pkg-config
SHLIBTOOL_OVERRIDE=	# empty

CONFIGURE_ARGS+=	--with-irssi=${WRKDIR}/${IRSSI_DISTNAME}

INSTALLATION_DIRS+=	share/doc/irssi

post-extract:
	cd ${WRKDIR} && ${LN} -s ${IRSSI_DISTNAME:S/a//} ${IRSSI_DISTNAME}
	${MV} ${WRKDIR}/${DISTNAME} ${WRKDIR}/${IRSSI_DISTNAME}
	${CP} ${IRSSI_CONFIG_H} ${WRKDIR}/${IRSSI_DISTNAME}/config.h
	${CP} ${IRSSI_CONFIG} ${WRKDIR}/${IRSSI_DISTNAME}/irssi-config

post-install:
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/irssi/README.icb

.include "../../devel/glib2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
