# $NetBSD: Makefile,v 1.1.1.1 2003/04/19 08:36:38 salo Exp $
#

DISTNAME=	beaver-0.2.6
WRKSRC=		${WRKDIR}/${DISTNAME}/src
CATEGORIES=	editors
MASTER_SITES=	http://savannah.nongnu.org/download/beaver/

MAINTAINER=	vincent.derrien@ahoup.net
HOMEPAGE=	http://www.beaver-project.org/
COMMENT=	Lightweight GTK+ text editor with syntax highlighting

USE_BUILDLINK2=	YES
USE_X11=	YES

.include "../../x11/gtk/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
