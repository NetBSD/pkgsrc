# $NetBSD: Makefile,v 1.37 2000/08/09 23:09:35 wiz Exp $
#

DISTNAME=		ORBit-0.5.3
CATEGORIES=		net
MASTER_SITES=		${MASTER_SITE_GNOME:=stable/sources/ORBit/}

MAINTAINER=		wiz@netbsd.org
HOMEPAGE=		http://www.gnome.org/

DEPENDS+=		glib>=1.2.7:../../devel/glib
DEPENDS+=		gindent-*:../../devel/gindent
DEPENDS+=		gettext>=0.10.35nb1:../../devel/gettext

USE_GMAKE=		# defined
USE_LIBTOOL=		# defined
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig \
			${WRKSRC}/popt/ltconfig \
			${WRKSRC}/libIDL/ltconfig

GNU_CONFIGURE=		# defined
CONFIGURE_ENV+=		CPPFLAGS="${CPPFLAGS}"
CPPFLAGS+=		-I${LOCALBASE}/include		# libintl.h

INFO_FILES=		libIDL.info

post-install:
	cd ${WRKSRC}/popt; ${LIBTOOL} --mode=install \
		${INSTALL_DATA} libpopt.la ${PREFIX}/lib

.include "../../mk/bsd.pkg.mk"
