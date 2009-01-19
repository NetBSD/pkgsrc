# $NetBSD: Makefile,v 1.25 2009/01/19 10:20:03 sketch Exp $
#

DISTNAME=	irssi-icb-0.14
PKGREVISION=	12
CATEGORIES=	chat
MASTER_SITES=	http://www.irssi.org/files/plugins/icb/
DISTFILES=	${DISTNAME}.tar.gz ${IRSSI_DISTFILE}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.irssi.org/
COMMENT=	Irssi plugin to access ICB networks

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../chat/irssi/Makefile.common"

WRKSRC=		${WRKDIR}/${IRSSI_DISTNAME}/${DISTNAME}

DEPENDS+=	irssi>=${IRSSI_VERSION}:../../chat/irssi

GNU_CONFIGURE=	yes

USE_LIBTOOL=	yes
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

.include "../../devel/glib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
