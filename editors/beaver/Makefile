# $NetBSD: Makefile,v 1.7 2004/04/11 08:03:29 snj Exp $
#

DISTNAME=	beaver-0.2.6
PKGREVISION=	3
CATEGORIES=	editors
MASTER_SITES=	http://savannah.nongnu.org/download/beaver/

MAINTAINER=	vincent.derrien@ahoup.net
HOMEPAGE=	http://www.nongnu.org/beaver/
COMMENT=	Lightweight GTK+ text editor with syntax highlighting

DEPENDS+=	xdg-dirs>=1.1:../../misc/xdg-dirs

WRKSRC=		${WRKDIR}/${DISTNAME}/src
USE_BUILDLINK3=	YES
USE_X11=	YES

.include "../../x11/gtk/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
