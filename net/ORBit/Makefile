# $NetBSD: Makefile,v 1.60 2001/08/26 10:32:22 skrll Exp $
#

DISTNAME=		ORBit-0.${ORBIT_MAJOR}.${ORBIT_MINOR}
CATEGORIES=		net
MASTER_SITES=		${MASTER_SITE_GNOME:=stable/sources/ORBit/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		wiz@netbsd.org
HOMEPAGE=		http://www.gnome.org/
COMMENT=		high-performance CORBA ORB with support for the C language

DEPENDS+=		gindent-*:../../devel/gindent
BUILD_DEPENDS+=		autoconf-2.13:../../devel/autoconf
BUILD_DEPENDS+=		automake>=1.4:../../devel/automake

BUILD_USES_GETTEXT_M4=	YES
USE_GMAKE=		YES
USE_LIBTOOL=		YES
LTCONFIG_OVERRIDE+=	${WRKSRC}/ltconfig
LTCONFIG_OVERRIDE+=	${WRKSRC}/popt/ltconfig
LTCONFIG_OVERRIDE+=	${WRKSRC}/libIDL/ltconfig

GNU_CONFIGURE=		YES
USE_BUILDLINK_ONLY=	YES
REPLACE_BUILDLINK=	libIDL/libIDLConf.sh

# for DISTNAME, PKGNAME, and PLIST
ORBIT_MAJOR=		5
ORBIT_MINOR=		8
PLIST_SUBST+=		ORBIT_MAJOR=${ORBIT_MAJOR} ORBIT_MINOR=${ORBIT_MINOR}

INFO_FILES=		libIDL.info

pre-configure:
	cd ${WRKSRC}/popt && ${LOCALBASE}/bin/autoreconf --include-deps --force

.include "../../devel/gettext-lib/buildlink.mk"
.include "../../devel/glib/buildlink.mk"
.include "../../security/tcp_wrappers/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
