# $NetBSD: Makefile,v 1.5 2005/12/29 06:22:04 jlam Exp $
#

DISTNAME=		whoson-2.03
PKGREVISION=		1
CATEGORIES=		net security
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=whoson/}

MAINTAINER=		abs@NetBSD.org
HOMEPAGE=		http://whoson.sf.net/
COMMENT=		Check if (dynamic) IP address is connected

EXDIR=		    	${PREFIX}/share/examples/whoson
CONF_FILES=    		${EXDIR}/whoson.conf ${PKG_SYSCONFDIR}/whoson.conf

USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
GNU_CONFIGURE=		yes
WHOSOND_CHROOT?=	${VARBASE}/chroot/whosond
CONFIGURE_ARGS+=	--with-config="${PKG_SYSCONFDIR}/whoson.conf"

FILES_SUBST+=		CHROOTDIR=${WHOSOND_CHROOT:Q}
DEINSTALL_EXTRA_TMPL+=	${.CURDIR}/DEINSTALL
INSTALL_EXTRA_TMPL+=	${.CURDIR}/INSTALL

RCD_SCRIPTS=		whosond

# Run this here as whoson's 'install' target will install if not present
pre-build:
	${SED} 's:@@CHROOTDIR@@:${WHOSOND_CHROOT}:g' < ${FILESDIR}/whoson.conf \
						> ${WRKSRC}/whoson.conf

post-install:
	${INSTALL_DATA_DIR} ${EXDIR}
	${INSTALL_DATA} ${WRKSRC}/whoson.conf ${EXDIR}/whoson.conf

.include "../../mk/bsd.pkg.mk"
