# $NetBSD: Makefile,v 1.11 2004/04/09 14:29:09 minskim Exp $
#

DISTNAME=	xchm-0.9.1
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=xchm/}

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://xchm.sourceforge.net/
COMMENT=	CHM viewer for UNIX

DEPENDS+=	xdg-dirs>=1.1:../../misc/xdg-dirs

USE_BUILDLINK3=		yes
USE_LANGUAGES=		c++
GNU_CONFIGURE=		yes
USE_PKGLOCALEDIR=	yes

.include "../../devel/chmlib/buildlink3.mk"
.include "../../x11/wxGTK/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
