# $NetBSD: Makefile,v 1.43 2001/01/14 12:19:34 tron Exp $
#

DISTNAME=		ORBit-0.5.6
CATEGORIES=		net
MASTER_SITES=		${MASTER_SITE_GNOME:=stable/sources/ORBit/}

MAINTAINER=		wiz@netbsd.org
HOMEPAGE=		http://www.gnome.org/

DEPENDS+=		glib>=1.2.7:../../devel/glib
DEPENDS+=		gindent-*:../../devel/gindent
BUILD_DEPENDS+=		autoconf:../../devel/autoconf
BUILD_DEPENDS+=		msgfmt:../../devel/gettext

USE_LIBINTL=		YES
USE_GMAKE=		YES
USE_LIBTOOL=		YES
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig \
			${WRKSRC}/popt/ltconfig \
			${WRKSRC}/libIDL/ltconfig

GNU_CONFIGURE=		YES
CONFIGURE_ENV+=		CPPFLAGS="${CPPFLAGS}"
CPPFLAGS+=		-I${LOCALBASE}/include		# libintl.h

INFO_FILES=		libIDL.info

pre-configure:
	cd ${WRKSRC}/popt && autoconf

.include "../../mk/bsd.pkg.mk"
