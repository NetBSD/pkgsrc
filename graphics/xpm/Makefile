# $NetBSD: Makefile,v 1.15 2000/11/25 08:42:04 tron Exp $
#

DISTNAME=       xpm-3.4k
CATEGORIES=	graphics x11
MASTER_SITES=	ftp://avahi.inria.fr/pub/xpm/

MAINTAINER=	mycroft@netbsd.org
HOMEPAGE=	http://www.inria.fr/koala/lehors/xpm.html

USE_IMAKE=	yes

.if !defined(CHECK_XPM)
IS_BUILTIN_XPM!=	${MAKE} CHECK_XPM=YES USE_XPM=YES VARNAME=IS_BUILTIN_XPM show-var
.if (${IS_BUILTIN_XPM} != "0")
IGNORE=		"The Xpm library is included in your X11 distribution."
.endif
.endif

.include "../../mk/bsd.pkg.mk"
