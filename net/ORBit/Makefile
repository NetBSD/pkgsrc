# $NetBSD: Makefile,v 1.25 1999/10/01 22:59:38 jlam Exp $
#

DISTNAME=	ORBit-0.4.3
CATEGORIES=	corba
MASTER_SITES=	${MASTER_SITE_GNOME:=gnome-1.0/sources/}

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.gnome.org/

DEPENDS+=	glib-1.2.4:../../devel/glib
DEPENDS+=	gindent-*:../../devel/gindent

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
