# $NetBSD: Makefile,v 1.53 2001/05/21 19:59:03 rh Exp $
#

DISTNAME=		ORBit-0.${ORBIT_MAJOR}.${ORBIT_MINOR}
CATEGORIES=		net
MASTER_SITES=		${MASTER_SITE_GNOME:=stable/sources/ORBit/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		wiz@netbsd.org
HOMEPAGE=		http://www.gnome.org/
COMMENT=		high-performance CORBA ORB with support for the C language

DEPENDS+=		glib>=1.2.7:../../devel/glib
DEPENDS+=		gindent-*:../../devel/gindent
BUILD_DEPENDS+=		autoconf-2.13:../../devel/autoconf
BUILD_DEPENDS+=		automake-1.4:../../devel/automake

USE_LIBINTL=		YES
USE_GMAKE=		YES
USE_LIBTOOL=		YES
LTCONFIG_OVERRIDE+=	${WRKSRC}/ltconfig
LTCONFIG_OVERRIDE+=	${WRKSRC}/popt/ltconfig
LTCONFIG_OVERRIDE+=	${WRKSRC}/libIDL/ltconfig

GNU_CONFIGURE=		YES
CONFIGURE_ENV+=		CPPFLAGS="${CPPFLAGS}"
MAKE_ENV+=		CPPFLAGS="${CPPFLAGS}"		# the build system runs
#							# configure again...
CPPFLAGS+=		-I${LOCALBASE}/include		# libintl.h

# for DISTNAME, PKGNAME, and PLIST
ORBIT_MAJOR=		5
ORBIT_MINOR=		8
PLIST_SUBST+=		ORBIT_MAJOR=${ORBIT_MAJOR} ORBIT_MINOR=${ORBIT_MINOR}

INFO_FILES=		libIDL.info

.include "../../mk/bsd.prefs.mk"

.if !exists(${LOCALBASE}/share/aclocal/gettext.m4)
BUILD_DEPENDS+=		gettext-0.10.35nb1:../../devel/gettext
.endif

.if (${OPSYS} == SunOS)
DEPENDS+=		tcp_wrappers>=7.6.1nb1:../../security/tcp_wrappers
.endif

pre-configure:
	cd ${WRKSRC}/popt && ${LOCALBASE}/bin/autoconf

.include "../../mk/bsd.pkg.mk"
