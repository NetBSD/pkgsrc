# $NetBSD: Makefile,v 1.5 2004/01/20 12:14:05 agc Exp $
#

DISTNAME=	beaver-0.2.6
PKGREVISION=	2
CATEGORIES=	editors
MASTER_SITES=	http://savannah.nongnu.org/download/beaver/

MAINTAINER=	vincent.derrien@ahoup.net
HOMEPAGE=	http://www.nongnu.org/beaver/
COMMENT=	Lightweight GTK+ text editor with syntax highlighting

WRKSRC=		${WRKDIR}/${DISTNAME}/src
USE_BUILDLINK2=	YES
USE_X11=	YES

.include "../../x11/gtk/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
