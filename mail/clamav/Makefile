# $NetBSD: Makefile,v 1.2 2003/05/02 11:55:37 wiz Exp $

DISTNAME=	clamav-0.54
PKGREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	http://clamav.elektrapro.com/stable/

MAINTAINER=	david@netbsd-fr.org
HOMEPAGE=	http://clamav.elektrapro.com/stable
COMMENT=	Anti-virus toolkit

USE_BUILDLINK2=		yes
GNU_CONFIGURE=		yes
USE_PKGINSTALL=		yes
USE_LIBTOOL=		yes
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
CONFIGURE_ARGS+=	--disable-clamav

PKG_GROUPS+=    ${CLAMAV_GROUP}
PKG_USERS+=     ${CLAMAV_USER}:${CLAMAV_GROUP}::Clamav\\ User

pre-configure:
	cd ${WRKSRC}; ${AUTOCONF}

# Remove the "annoying" strings.h in libclamav
pre-build:
	${RM} ${WRKSRC}/libclamav/strings.h

.include "../../mk/pthread.buildlink2.mk"
.include "../../mk/autoconf.mk"
.include "../../mk/bsd.pkg.mk"
