# $NetBSD: Makefile,v 1.4 2003/07/13 13:51:29 wiz Exp $
#

DISTNAME=	beaver-0.2.6
PKGREVISION=	2
WRKSRC=		${WRKDIR}/${DISTNAME}/src
CATEGORIES=	editors
MASTER_SITES=	http://savannah.nongnu.org/download/beaver/

MAINTAINER=	vincent.derrien@ahoup.net
HOMEPAGE=	http://www.nongnu.org/beaver/
COMMENT=	Lightweight GTK+ text editor with syntax highlighting

USE_BUILDLINK2=	YES
USE_X11=	YES

.include "../../x11/gtk/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
