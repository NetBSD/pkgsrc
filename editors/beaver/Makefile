# $NetBSD: Makefile,v 1.13 2008/06/20 01:09:17 joerg Exp $
#

DISTNAME=	beaver-0.2.6
PKGREVISION=	5
CATEGORIES=	editors
MASTER_SITES=	http://savannah.nongnu.org/download/beaver/

MAINTAINER=	vincent.derrien@ahoup.net
HOMEPAGE=	http://www.nongnu.org/beaver/
COMMENT=	Lightweight GTK+ text editor with syntax highlighting

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/${DISTNAME}/src
USE_DIRS+=	xdg-1.1

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1 share/pixmaps

.include "../../x11/gtk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
