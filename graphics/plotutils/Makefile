# $NetBSD: Makefile,v 1.7 2000/07/18 07:41:24 itohy Exp $
#

DISTNAME=	plotutils-2.3
# ".0" is added to distinguish libplotter enabled version and existent pkg.
# If you update the base source above 2.3, this hack will no longer needed.
PKGNAME=	plotutils-2.3.0
CATEGORIES=	devel graphics x11
MASTER_SITES=	${MASTER_SITE_GNU:=plotutils/}

MAINTAINER=	dmcmahill@netbsd.org
HOMEPAGE=	http://www.gnu.org/software/plotutils/plotutils.html

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--enable-libplotter

USE_PKGLIBTOOL=	yes
USE_X11BASE=	yes

INFO_FILES=	plotutils.info

.include "../../mk/bsd.pkg.mk"
