# $NetBSD: Makefile,v 1.24 2004/02/20 13:08:21 jmmv Exp $

DISTNAME=	seahorse-0.7.3
PKGREVISION=	9
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=seahorse/}

MAINTAINER=	jmmv@NetBSD.org
HOMEPAGE=	http://seahorse.sourceforge.net/
COMMENT=	GnuPG front end and bonobo component for Gnome

BUILD_USES_MSGFMT=	yes
DEPENDS+=		gnupg>=1.2.1:../../security/gnupg
DEPENDS+=		gnome2-dirs>=1.1:../../misc/gnome2-dirs

GNU_CONFIGURE=		yes
USE_GNU_TOOLS+=		make
USE_X11=		yes
USE_BUILDLINK3=		yes
USE_PKGLOCALEDIR=	yes

GCONF2_SCHEMAS= 	seahorse.schemas

.include "../../databases/gnome-mime-data/buildlink3.mk"
.include "../../devel/eel2/buildlink3.mk"
.include "../../devel/GConf2/schemas.mk"
.include "../../devel/libbonobo/buildlink3.mk"
.include "../../devel/libbonoboui/buildlink3.mk"
.include "../../devel/libglade2/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../security/gpgme03/buildlink3.mk"
.include "../../textproc/intltool/buildlink3.mk"
.include "../../textproc/scrollkeeper/omf.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
