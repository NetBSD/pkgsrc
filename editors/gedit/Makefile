# $NetBSD: Makefile,v 1.16 2003/12/13 00:45:23 wiz Exp $
#

DISTNAME=		gedit-2.2.1
PKGREVISION=		5
CATEGORIES=		editors gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/gedit/2.2/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://gedit.sourceforge.net/
COMMENT=		Lightweight GNOME2 text editor

BUILD_USES_MSGFMT=	YES
DEPENDS+=		gnome2-dirs>=1.2:../../misc/gnome2-dirs

USE_PERL5=		build
USE_BUILDLINK2=		YES
USE_PKGLOCALEDIR=	YES
USE_GMAKE=		YES
USE_X11=		YES
USE_LIBTOOL=		YES
GNU_CONFIGURE=		YES
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

GCONF2_SCHEMAS=		gedit.schemas

.include "../../textproc/scrollkeeper/omf.mk"
.include "../../print/libgnomeprintui/buildlink2.mk"
.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../devel/GConf2/schemas.mk"
.include "../../devel/libgnomeui/buildlink2.mk"
.include "../../devel/eel2/buildlink2.mk"
.include "../../devel/popt/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
