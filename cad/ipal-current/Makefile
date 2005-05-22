# $NetBSD: Makefile,v 1.20 2005/05/22 20:07:41 jlam Exp $
#

DISTNAME=	ipal-20001210
PKGNAME=	ipal-current-20001210
PKGREVISION=	3
CATEGORIES=	cad
MASTER_SITES=	ftp://icarus.com/pub/eda/ipal/snapshots/

MAINTAINER=	dmcmahill@NetBSD.org
HOMEPAGE=	http://www.icarus.com/eda/ipal/index.html
COMMENT=	Libs and utils for manipulating PAL designs (development version)

BUILD_DEPENDS+= bison-[0-9]*:../../devel/bison

GNU_CONFIGURE=	YES
USE_TOOLS+=	gmake lex

CFLAGS+=	-fPIC

.include "../../x11/gtk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
