# $NetBSD: Makefile,v 1.1.1.1 2001/09/08 23:03:02 manu Exp $
#

DISTNAME=	aalib-1.2
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=aa-project/}

MAINTAINER=	manu@netbsd.org
HOMEPAGE=	http://aa-project.sourceforge.net/aalib/
COMMENT=	ASCII Art library

DEPENDS+=	ncurses>=5.2:../../devel/ncurses

GNU_CONFIGURE=	YES
CONFIGURE_ARGS+= --with-ncurses=${LOCALBASE}

CFLAGS+=	-DPIC -fPIC

.include "../../mk/bsd.pkg.mk"
