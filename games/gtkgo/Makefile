# $NetBSD: Makefile,v 1.2 2003/05/02 11:54:58 wiz Exp $
#

DISTNAME=	gtkgo-0_0_10
PKGREVISION=	1
PKGNAME=	${DISTNAME:S/_/./g}
WRKSRC=		${WRKDIR}/${PKGNAME}
CATEGORIES=	games gnome
MASTER_SITES=	http://norbertdejonge.sourceforge.net/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://norbertdejonge.sourceforge.net/gtkgo.html
COMMENT=	Go board with skin support

USE_X11=	YES
USE_BUILDLINK2=	YES
GNU_CONFIGURE=	YES
CPPFLAGS+=	-DPKGDATADIR='\"${PREFIX}/share/gtkgo/\"'

.include "../../x11/gnome-libs/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
