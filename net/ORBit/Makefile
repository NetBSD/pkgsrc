# $NetBSD: Makefile,v 1.50 2001/03/10 23:36:22 tron Exp $
#

DISTNAME=		ORBit-0.5.6
CATEGORIES=		net
MASTER_SITES=		${MASTER_SITE_GNOME:=stable/sources/ORBit/}

MAINTAINER=		wiz@netbsd.org
HOMEPAGE=		http://www.gnome.org/
COMMENT=		high-performance CORBA ORB with support for the C language

DEPENDS+=		glib>=1.2.7:../../devel/glib
DEPENDS+=		gindent-*:../../devel/gindent
BUILD_DEPENDS+=		${LOCALBASE}/bin/autoconf:../../devel/autoconf
BUILD_DEPENDS+=		${LOCALBASE}/bin/automake:../../devel/automake
BUILD_DEPENDS+=		${LOCALBASE}/share/aclocal/gettext.m4:../../devel/gettext

USE_LIBINTL=		YES
USE_GMAKE=		YES
USE_LIBTOOL=		YES
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig \
			${WRKSRC}/popt/ltconfig \
			${WRKSRC}/libIDL/ltconfig

GNU_CONFIGURE=		YES
CONFIGURE_ENV+=		CPPFLAGS="${CPPFLAGS}"
MAKE_ENV+=		CPPFLAGS="${CPPFLAGS}"		# the build system runs
#							# configure again...
CPPFLAGS+=		-I${LOCALBASE}/include		# libintl.h

INFO_FILES=		libIDL.info

.include "../../mk/bsd.prefs.mk"

.if (${OPSYS} == SunOS)
DEPENDS+=		tcp_wrappers>=7.6.1nb1:../../security/tcp_wrappers
.endif

pre-configure:
	cd ${WRKSRC}/popt && ${LOCALBASE}/bin/autoconf

.include "../../mk/bsd.pkg.mk"
