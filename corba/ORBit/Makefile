# $NetBSD: Makefile,v 1.28 2000/01/02 18:02:40 tron Exp $
#

DISTNAME=	ORBit-0.5.0
CATEGORIES=	corba
MASTER_SITES=	${MASTER_SITE_GNOME:=stable/releases/gnome-1.0.53/}

MAINTAINER=	tron@netbsd.org
HOMEPAGE=	http://www.gnome.org/

DEPENDS+=	glib-1.2.*:../../devel/glib
DEPENDS+=	gindent-*:../../devel/gindent
DEPENDS+=	gettext-0.10.*:../../devel/gettext

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_GMAKE=	yes

LIBTOOL_FLAGS=	--install-la
INFO_FILES=	libIDL.info

# This package fails to build, with an unterminated macro definition error
# Calling the build twice seems to workaround this.
do-build:
	 -@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${GMAKE} ${.MAKEFLAGS} all
	 -@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${GMAKE} ${.MAKEFLAGS} all

.include "../../mk/bsd.pkg.mk"
