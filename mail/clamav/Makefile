# $NetBSD: Makefile,v 1.3 2003/06/07 17:39:15 jmmv Exp $

DISTNAME=	clamav-0.54
PKGREVISION=	2
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
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}

PKG_GROUPS+=    ${CLAMAV_GROUP}
PKG_USERS+=     ${CLAMAV_USER}:${CLAMAV_GROUP}::Clamav\\ User

EGDIR=		${PREFIX}/share/examples/clamav
CONF_FILES=	${EGDIR}/clamav.conf ${PKG_SYSCONFDIR}/clamav.conf

pre-configure:
	cd ${WRKSRC}; ${AUTOCONF}

# Remove the "annoying" strings.h in libclamav
pre-build:
	${RM} ${WRKSRC}/libclamav/strings.h

.include "../../mk/pthread.buildlink2.mk"
.include "../../mk/autoconf.mk"
.include "../../mk/bsd.pkg.mk"
