# $NetBSD: Makefile,v 1.16 2004/04/25 21:37:59 recht Exp $

DISTNAME=	clamav-${CLAMAV_VERSION}
PKGNAME=	clamav-${CLAMAV_VERSION:S/-/./}
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=clamav/}

MAINTAINER=	david@netbsd-fr.org
HOMEPAGE=	http://www.clamav.net/
COMMENT=	Anti-virus toolkit

CLAMAV_VERSION=	0.70

USE_BUILDLINK3=		yes
GNU_CONFIGURE=		yes
USE_PKGINSTALL=		yes
USE_LIBTOOL=		yes
# disable the configure check for user and group:
CONFIGURE_ARGS+=	--disable-clamav
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--with-uid=${CLAMAV_USER}
CONFIGURE_ARGS+=	--with-group=${CLAMAV_GROUP}
CONFIGURE_ARGS+=	--with-tcpwrappers

BUILD_DEFS+=	CLAMAV_USER CLAMAV_GROUP USE_MILTER

RCD_SCRIPTS=	clamd
PKG_GROUPS+=    ${CLAMAV_GROUP}
PKG_USERS+=     ${CLAMAV_USER}:${CLAMAV_GROUP}::Clamav\\ User

EGDIR=		${PREFIX}/share/examples/clamav
CONF_FILES=	${EGDIR}/clamav.conf ${PKG_SYSCONFDIR}/clamav.conf
CONF_FILES+=	${EGDIR}/freshclam.conf ${PKG_SYSCONFDIR}/freshclam.conf
PLIST_SRC=	${PKGDIR}/PLIST

.include "../../mk/bsd.prefs.mk"
.if defined(USE_MILTER) && !empty(USE_MILTER:M[yY][eE][sS])
.include "../../mail/libmilter/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-milter
PLIST_SRC+=		${PKGDIR}/PLIST.milter
.else
CONFIGURE_ARGS+=	--disable-milter
# XXX --disable-milter doesn't work as expected, so we need this
CONFIGURE_ENV+=		ac_cv_header_libmilter_mfapi_h=no
.endif

# for freshclam to work it must own the share/clamav dir
post-install:
	${CHOWN} -R ${CLAMAV_USER}:${CLAMAV_GROUP} ${PREFIX}/share/clamav

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../devel/gmp/buildlink3.mk"
.include "../../security/tcp_wrappers/buildlink3.mk"

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
