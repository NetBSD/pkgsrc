# $NetBSD: Makefile,v 1.3 2004/10/03 00:14:39 tv Exp $
#

DISTNAME=	poedit-1.2.5
PKGREVISION=	1
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=poedit/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://poedit.sourceforge.net/
COMMENT=	Cross-platform gettext catalogs (.po files) editor

DEPENDS+=	zip-[0-9]*:../../archivers/zip

USE_BUILDLINK3=		yes
GNU_CONFIGURE=		yes
USE_PKGLOCALEDIR=	yes
USE_GNU_TOOLS+=		make
USE_X11=		yes

.include "../../databases/db4/buildlink3.mk"
.include "../../x11/wxGTK/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
