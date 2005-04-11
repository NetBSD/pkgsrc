# $NetBSD: Makefile,v 1.13 2005/04/11 21:45:51 tv Exp $
#

DISTNAME=	gtkgo-0_0_10
PKGNAME=	${DISTNAME:S/_/./g}
PKGREVISION=	4
CATEGORIES=	games gnome
MASTER_SITES=	http://norbertdejonge.sourceforge.net/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://norbertdejonge.sourceforge.net/gtkgo.html
COMMENT=	Go board with skin support

CPPFLAGS+=	-DPKGDATADIR='"${PREFIX}/share/gtkgo/"'
GNU_CONFIGURE=	YES
USE_X11=	YES
WRKSRC=		${WRKDIR}/${DISTNAME:S/_/./g}

.include "../../x11/gnome-libs/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
