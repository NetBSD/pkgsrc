# $NetBSD: Makefile,v 1.11 2003/05/02 13:07:52 wiz Exp $
#

DISTNAME=	ipal-20001210
PKGREVISION=	1
PKGNAME=	ipal-current-20001210
CATEGORIES=	cad
MASTER_SITES=	ftp://icarus.com/pub/eda/ipal/snapshots/

MAINTAINER=	dmcmahill@netbsd.org
HOMEPAGE=	http://www.icarus.com/eda/ipal/index.html
COMMENT=	Libs and utils for manipulating PAL designs (development version)

BUILD_DEPENDS+= bison-[0-9]*:../../devel/bison

GNU_CONFIGURE=	YES
USE_BUILDLINK2=	YES
USE_GMAKE=	YES

CFLAGS+=	-fPIC

.include "../../x11/gtk/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
