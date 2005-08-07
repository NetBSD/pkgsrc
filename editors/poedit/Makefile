# $NetBSD: Makefile,v 1.8 2005/08/07 11:29:03 wiz Exp $
#

DISTNAME=	poedit-1.2.5
PKGREVISION=	3
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=poedit/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://poedit.sourceforge.net/
COMMENT=	Cross-platform gettext catalogs (.po files) editor

DEPENDS+=	zip-[0-9]*:../../archivers/zip

GNU_CONFIGURE=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake
CONFIGURE_ENV+=		WX_CONFIG_NAME=${LOCALBASE}/bin/wx24-config

.include "../../databases/db4/buildlink3.mk"
.include "../../x11/wxGTK24/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
