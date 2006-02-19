# $NetBSD: Makefile,v 1.6 2006/02/19 23:08:48 wiz Exp $
#

DISTNAME=		whoson-2.03
PKGREVISION=		2
CATEGORIES=		net security
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=whoson/}

MAINTAINER=		abs@NetBSD.org
HOMEPAGE=		http://whoson.sf.net/
COMMENT=		Check if (dynamic) IP address is connected

USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
WHOSOND_CHROOT?=	${VARBASE}/chroot/whosond
CONFIGURE_ARGS+=	--with-config="${PKG_SYSCONFDIR}/whoson.conf"

RCD_SCRIPTS=		whosond
OWN_DIRS+=		${WHOSOND_CHROOT}
EXDIR=		    	${PREFIX}/share/examples/whoson
CONF_FILES=    		${EXDIR}/whoson.conf ${PKG_SYSCONFDIR}/whoson.conf

# Run this here as whoson's 'install' target will install if not present
pre-build:
	${SED} 's:@@CHROOTDIR@@:${WHOSOND_CHROOT}:g' < ${FILESDIR}/whoson.conf \
						> ${WRKSRC}/whoson.conf

post-install:
	${INSTALL_DATA_DIR} ${EXDIR}
	${INSTALL_DATA} ${WRKSRC}/whoson.conf ${EXDIR}/whoson.conf

.include "../../mk/bsd.pkg.mk"
