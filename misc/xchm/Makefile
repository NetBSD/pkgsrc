# $NetBSD: Makefile,v 1.12 2004/04/14 16:15:25 jmmv Exp $
#

DISTNAME=	xchm-0.9.1
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=xchm/}

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://xchm.sourceforge.net/
COMMENT=	CHM viewer for UNIX

USE_BUILDLINK3=		yes
USE_DIRS+=		xdg-1.1
USE_LANGUAGES=		c++
GNU_CONFIGURE=		yes
USE_PKGLOCALEDIR=	yes

.include "../../devel/chmlib/buildlink3.mk"
.include "../../x11/wxGTK/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
