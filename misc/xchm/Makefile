# $NetBSD: Makefile,v 1.32 2006/04/17 13:46:41 wiz Exp $
#

DISTNAME=	xchm-1.7.1
PKGREVISION=	1
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=xchm/}

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://xchm.sourceforge.net/
COMMENT=	CHM viewer for UNIX

USE_DIRS+=		xdg-1.1
USE_LANGUAGES=		c++
GNU_CONFIGURE=		yes
USE_PKGLOCALEDIR=	yes

.include "../../devel/chmlib/buildlink3.mk"
.include "../../x11/wxGTK/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
