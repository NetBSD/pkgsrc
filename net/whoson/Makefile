# $NetBSD: Makefile,v 1.15 2020/03/20 11:58:12 nia Exp $
#

DISTNAME=		whoson-2.05
CATEGORIES=		net security
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=whoson/}

MAINTAINER=		abs@NetBSD.org
HOMEPAGE=		http://whoson.sourceforge.net/
COMMENT=		Check if (dynamic) IP address is connected

MAKE_JOBS_SAFE=		no

USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
WHOSOND_CHROOT?=	${VARBASE}/chroot/whosond
CONFIGURE_ARGS+=	--with-config="${PKG_SYSCONFDIR}/whoson.conf"

RCD_SCRIPTS=	whosond
OWN_DIRS+=	${WHOSOND_CHROOT}
EXDIR=		${PREFIX}/share/examples/whoson
CONF_FILES=	${EXDIR}/whoson.conf ${PKG_SYSCONFDIR}/whoson.conf

INSTALLATION_DIRS=	${EXDIR}

# Run this here as whoson's 'install' target will install if not present
pre-build:
	${SED} 's:@@CHROOTDIR@@:${WHOSOND_CHROOT}:g' < ${FILESDIR}/whoson.conf \
						> ${WRKSRC}/whoson.conf

post-install:
	${INSTALL_DATA} ${WRKSRC}/whoson.conf ${DESTDIR}${EXDIR}/whoson.conf

.include "../../mk/bsd.pkg.mk"
