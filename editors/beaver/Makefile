# $NetBSD: Makefile,v 1.8 2004/04/14 16:15:22 jmmv Exp $
#

DISTNAME=	beaver-0.2.6
PKGREVISION=	3
CATEGORIES=	editors
MASTER_SITES=	http://savannah.nongnu.org/download/beaver/

MAINTAINER=	vincent.derrien@ahoup.net
HOMEPAGE=	http://www.nongnu.org/beaver/
COMMENT=	Lightweight GTK+ text editor with syntax highlighting

WRKSRC=		${WRKDIR}/${DISTNAME}/src
USE_BUILDLINK3=	YES
USE_DIRS+=	xdg-1.1
USE_X11=	YES

.include "../../x11/gtk/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
