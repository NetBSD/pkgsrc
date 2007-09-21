# $NetBSD: Makefile,v 1.13 2007/09/21 13:03:56 wiz Exp $

DISTNAME=	gpredict-0.8.0
PKGREVISION=	1
CATEGORIES=	ham
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=groundstation/}

MAINTAINER=	wulf@NetBSD.org
HOMEPAGE=	http://groundstation.sourceforge.net/
COMMENT=	Gnome satellite tracking program

USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake msgfmt pkg-config intltool
USE_PKGLOCALEDIR=yes
GNU_CONFIGURE=	yes

.include "../../devel/GConf/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
#.include "../../ham/hamlib/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
