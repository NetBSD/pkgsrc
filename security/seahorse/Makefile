# $NetBSD: Makefile,v 1.15 2003/11/12 01:31:51 salo Exp $

DISTNAME=	seahorse-0.7.3
PKGREVISION=	3
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=seahorse/}

MAINTAINER=	jmmv@NetBSD.org
HOMEPAGE=	http://seahorse.sourceforge.net/
COMMENT=	GnuPG front end and bonobo component for Gnome

BUILD_USES_MSGFMT=	yes
DEPENDS+=		gnupg>=1.2.1:../../security/gnupg
DEPENDS+=		gnome2-dirs>=1.1:../../misc/gnome2-dirs

GNU_CONFIGURE=		yes
USE_GMAKE=		yes
USE_X11=		yes
USE_BUILDLINK2=		yes
USE_PKGLOCALEDIR=	yes

GCONF2_SCHEMAS= 	seahorse.schemas

.include "../../databases/gnome-mime-data/buildlink2.mk"
.include "../../devel/GConf2/schemas.mk"
.include "../../devel/bonobo-activation/buildlink2.mk"
.include "../../devel/eel2/buildlink2.mk"
.include "../../devel/libglade2/buildlink2.mk"
.include "../../devel/libgnomeui/buildlink2.mk"
.include "../../security/gpgme/buildlink2.mk"
.include "../../textproc/scrollkeeper/omf.mk"
.include "../../x11/gtk2/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
