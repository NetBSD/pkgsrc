# $NetBSD: Makefile,v 1.10 2004/03/08 19:40:41 jmmv Exp $
#

DISTNAME=	xchm-0.9
PKGREVISION=	1
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=xchm/}

MAINTAINER=	tech-pkg@NetBSD.org
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
