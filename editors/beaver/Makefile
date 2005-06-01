# $NetBSD: Makefile,v 1.11 2005/06/01 18:02:45 jlam Exp $
#

DISTNAME=	beaver-0.2.6
PKGREVISION=	4
CATEGORIES=	editors
MASTER_SITES=	http://savannah.nongnu.org/download/beaver/

MAINTAINER=	vincent.derrien@ahoup.net
HOMEPAGE=	http://www.nongnu.org/beaver/
COMMENT=	Lightweight GTK+ text editor with syntax highlighting

WRKSRC=		${WRKDIR}/${DISTNAME}/src
USE_DIRS+=	xdg-1.1

.include "../../x11/gtk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
