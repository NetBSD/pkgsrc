# $NetBSD: Makefile,v 1.1.1.1 2000/11/19 17:05:28 dmcmahill Exp $
#

DISTNAME=	ipal-20001118
PKGNAME=	ipal-current-20001118
CATEGORIES=	cad
MASTER_SITES=	ftp://icarus.com/pub/eda/ipal/

MAINTAINER=	dmcmahill@netbsd.org

BUILD_DEPENDS+= bison:../../devel/bison
DEPENDS+=       gtk+>=1.2.7:../../x11/gtk

GNU_CONFIGURE=	YES
USE_GMAKE=	YES
USE_X11=	YES

.include "../../mk/bsd.pkg.mk"
