# $NetBSD: Makefile,v 1.5 2003/09/28 23:39:24 chris Exp $

DISTNAME=	clamav-0.60
PKGREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=clamav/}

MAINTAINER=	david@netbsd-fr.org
HOMEPAGE=	http://clamav.elektrapro.com/
COMMENT=	Anti-virus toolkit

AUTOCONF_REQD=		2.53	# clamav used 2.53
USE_BUILDLINK2=		yes
GNU_CONFIGURE=		yes
USE_PKGINSTALL=		yes
USE_LIBTOOL=		yes
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
# disable the configure check for user and group:
CONFIGURE_ARGS+=	--disable-clamav
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--with-uid=${CLAMAV_USER}
CONFIGURE_ARGS+=	--with-group=${CLAMAV_GROUP}

BUILD_DEFS+=	CLAMAV_USER CLAMAV_GROUP USE_MILTER

PKG_GROUPS+=    ${CLAMAV_GROUP}
PKG_USERS+=     ${CLAMAV_USER}:${CLAMAV_GROUP}::Clamav\\ User

EGDIR=		${PREFIX}/share/examples/clamav
CONF_FILES=	${EGDIR}/clamav.conf ${PKG_SYSCONFDIR}/clamav.conf
PLIST_SRC=	${PKGDIR}/PLIST

.include "../../mk/bsd.prefs.mk"
.if defined(USE_MILTER) && ${USE_MILTER} == "YES"
#.include "../../mail/libmilter/buildlink2.mk"
#CONFIGURE_ARGS+=	--enable-milter
#PLIST_SRC+=		${PKGDIR}/PLIST.milter
.else
CONFIGURE_ARGS+=	--disable-milter
.endif

pre-configure:
	cd ${WRKSRC};						\
	${ACLOCAL};						\
	${AUTOMAKE} -a --foreign -i;				\
	${AUTOCONF}

# for freshclam to work it must own the share/clamav dir
post-install:
	${CHOWN} -R ${CLAMAV_USER}:${CLAMAV_GROUP} ${PREFIX}/share/clamav

.include "../../devel/zlib/buildlink2.mk"
.include "../../archivers/bzip2/buildlink2.mk"
.include "../../mk/pthread.buildlink2.mk"
.include "../../mk/autoconf.mk"
.include "../../mk/automake.mk"
.include "../../mk/bsd.pkg.mk"
