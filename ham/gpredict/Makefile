# $NetBSD: Makefile,v 1.71 2020/05/22 10:56:14 adam Exp $

DISTNAME=	gpredict-2.2.1
PKGREVISION=	2
CATEGORIES=	ham
MASTER_SITES=	${MASTER_SITE_GITHUB:=csete/}
GITHUB_RELEASE=	v${PKGVERSION_NOREV}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://sourceforge.net/projects/gpredict/
COMMENT=	Gnome satellite tracking program
LICENSE=	gnu-gpl-v2

# runtime dependency only
DEPENDS+=	hamlib-[0-9]*:../../ham/hamlib

USE_LANGUAGES=		c c++
USE_TOOLS+=		gmake msgfmt pkg-config intltool
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../graphics/goocanvas2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
