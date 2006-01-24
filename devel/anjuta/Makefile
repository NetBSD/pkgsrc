# $NetBSD: Makefile,v 1.35 2006/01/24 07:32:00 wiz Exp $

DISTNAME=	anjuta-1.2.3
PKGREVISION=	3
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=anjuta/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.anjuta.org/
COMMENT=	Gnome based IDE for C and C++

DEPENDS+=	autoconf>=2.59:../../devel/autoconf
DEPENDS+=	automake>=1.8.2:../../devel/automake
DEPENDS+=	gettext>=0.11.5:../../devel/gettext
DEPENDS+=	glade2>=2.6.0:../../devel/glade2
DEPENDS+=	gnome2-terminal>=2.4.2:../../x11/gnome2-terminal
DEPENDS+=	libtool>=1.5.2:../../devel/libtool
DEPENDS+=	yelp>=2.4.2:../../misc/yelp

USE_DIRS+=		gnome2-1.5
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake:run pkg-config:run
GNU_CONFIGURE=		yes

SUBST_CLASSES+=		make
SUBST_STAGE.make=	pre-configure
SUBST_MESSAGE.make=	"Fixing path to GNU make."
SUBST_FILES.make=	data/properties/anjuta.properties
SUBST_FILES.make+=	src/defaults.c
SUBST_SED.make=		-e 's|make=make|make=${GMAKE}|'

SUBST_CLASSES+=		unused
SUBST_STAGE.unused=	pre-configure
SUBST_MESSAGE.unused=	"Fixing __unused__ occurrances to avoid name clash"
SUBST_FILES.unused=	tagmanager/c.c tagmanager/ctags.c tagmanager/general.h
SUBST_FILES.unused+=	tagmanager/lua.c tagmanager/options.c tagmanager/parse.c
SUBST_FILES.unused+=	tagmanager/parse.h tagmanager/regex.c
SUBST_FILES.unused+=	tagmanager/tm_file_entry.c tagmanager/tm_project.c
SUBST_FILES.unused+=	tagmanager/tm_source_file.c tagmanager/tm_workspace.c
SUBST_SED.unused=	-e 's/__unused__/_exctags_unused_/g'

.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../devel/pcre/buildlink3.mk"
.include "../../print/libgnomeprintui/buildlink3.mk"
.include "../../textproc/scrollkeeper/omf.mk"
.include "../../x11/vte/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
