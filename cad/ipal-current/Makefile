# $NetBSD: Makefile,v 1.3 2000/12/09 18:28:12 dmcmahill Exp $
#

DISTNAME=	ipal-20001122
PKGNAME=	ipal-current-20001122
CATEGORIES=	cad
MASTER_SITES=	ftp://icarus.com/pub/eda/ipal/snapshots/

MAINTAINER=	dmcmahill@netbsd.org
HOMEPAGE=	http://www.icarus.com/eda/ipal/index.html

BUILD_DEPENDS+= bison:../../devel/bison
DEPENDS+=       gtk+>=1.2.7:../../x11/gtk

GNU_CONFIGURE=	YES
USE_GMAKE=	YES
USE_X11=	YES

.include "../../mk/bsd.pkg.mk"
