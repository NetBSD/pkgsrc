# $NetBSD: Makefile,v 1.32 2000/06/20 22:42:38 jlam Exp $
#

DISTNAME=		ORBit-0.5.1
CATEGORIES=		net
MASTER_SITES=		${MASTER_SITE_GNOME:=stable/sources/ORBit/}

MAINTAINER=		tron@netbsd.org
HOMEPAGE=		http://www.gnome.org/

DEPENDS+=		glib-1.2.*:../../devel/glib
DEPENDS+=		gindent-*:../../devel/gindent
DEPENDS+=		gettext-0.10.*:../../devel/gettext

USE_GMAKE=		# defined
GNU_CONFIGURE=		# defined
USE_LIBTOOL=		# defined
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig \
			${WRKSRC}/popt/ltconfig \
			${WRKSRC}/libIDL/ltconfig

INFO_FILES=		libIDL.info

# This package fails to build, with an unterminated macro definition error
# Calling the build twice seems to workaround this.
do-build:
	 -@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${GMAKE} ${.MAKEFLAGS} all
	 -@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${GMAKE} ${.MAKEFLAGS} all

post-install:
	cd ${WRKSRC}/popt; ${LIBTOOL} --mode=install \
		${INSTALL_DATA} libpopt.la ${PREFIX}/lib

.include "../../mk/bsd.pkg.mk"
