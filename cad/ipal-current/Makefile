# $NetBSD: Makefile,v 1.16 2004/04/11 05:27:16 snj Exp $
#

DISTNAME=	ipal-20001210
PKGNAME=	ipal-current-20001210
PKGREVISION=	2
CATEGORIES=	cad
MASTER_SITES=	ftp://icarus.com/pub/eda/ipal/snapshots/

MAINTAINER=	dmcmahill@NetBSD.org
HOMEPAGE=	http://www.icarus.com/eda/ipal/index.html
COMMENT=	Libs and utils for manipulating PAL designs (development version)

BUILD_DEPENDS+= bison-[0-9]*:../../devel/bison

GNU_CONFIGURE=	YES
USE_BUILDLINK3=	YES
USE_GNU_TOOLS+=	make

CFLAGS+=	-fPIC

.include "../../x11/gtk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
