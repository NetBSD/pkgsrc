# $NetBSD: Makefile,v 1.9 2001/09/27 23:17:46 jlam Exp $
#

DISTNAME=	ipal-20001210
PKGNAME=	ipal-current-20001210
CATEGORIES=	cad
MASTER_SITES=	ftp://icarus.com/pub/eda/ipal/snapshots/

MAINTAINER=	dmcmahill@netbsd.org
HOMEPAGE=	http://www.icarus.com/eda/ipal/index.html
COMMENT=	Libs and utils for manipulating PAL designs (development version)

BUILD_DEPENDS+= bison-[0-9]*:../../devel/bison
DEPENDS+=       gtk+>=1.2.7:../../x11/gtk

GNU_CONFIGURE=	YES
USE_GMAKE=	YES
USE_X11=	YES

CFLAGS+=	-fPIC

post-patch:
	${CHMOD} a+x ${WRKSRC}/configure

.include "../../mk/bsd.pkg.mk"
