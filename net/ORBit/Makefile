# $NetBSD: Makefile,v 1.33 2000/07/10 10:52:18 wiz Exp $
#

DISTNAME=		ORBit-0.5.2
CATEGORIES=		net
MASTER_SITES=		${MASTER_SITE_GNOME:=stable/sources/ORBit/}

MAINTAINER=		tron@netbsd.org
HOMEPAGE=		http://www.gnome.org/

DEPENDS+=		glib>=1.2.7:../../devel/glib
DEPENDS+=		gindent-*:../../devel/gindent
DEPENDS+=		gettext-0.10.*:../../devel/gettext

USE_GMAKE=		# defined
GNU_CONFIGURE=		# defined
USE_LIBTOOL=		# defined
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig \
			${WRKSRC}/popt/ltconfig \
			${WRKSRC}/libIDL/ltconfig

INFO_FILES=		libIDL.info

post-install:
	cd ${WRKSRC}/popt; ${LIBTOOL} --mode=install \
		${INSTALL_DATA} libpopt.la ${PREFIX}/lib

.include "../../mk/bsd.pkg.mk"
