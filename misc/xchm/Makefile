# $NetBSD: Makefile,v 1.8 2004/03/03 22:42:10 minskim Exp $
#

DISTNAME=	xchm-0.9
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=xchm/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://xchm.sourceforge.net/
COMMENT=	CHM viewer for UNIX

USE_BUILDLINK2=		yes
USE_LANGUAGES=		c++
GNU_CONFIGURE=		yes
USE_PKGLOCALEDIR=	yes

.include "../../devel/chmlib/buildlink2.mk"
.include "../../x11/wxGTK/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
