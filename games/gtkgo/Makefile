# $NetBSD: Makefile,v 1.9 2004/01/20 12:15:40 agc Exp $
#

DISTNAME=	gtkgo-0_0_10
PKGBASE=	${DISTNAME:S/_/./g}
PKGNAME=	${PKGBASE}
PKGREVISION=	3
CATEGORIES=	games gnome
MASTER_SITES=	http://norbertdejonge.sourceforge.net/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://norbertdejonge.sourceforge.net/gtkgo.html
COMMENT=	Go board with skin support

WRKSRC=		${WRKDIR}/${PKGBASE}
USE_X11=	YES
USE_BUILDLINK2=	YES
GNU_CONFIGURE=	YES
CPPFLAGS+=	-DPKGDATADIR='\"${PREFIX}/share/gtkgo/\"'

.include "../../x11/gnome-libs/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
