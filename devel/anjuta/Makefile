# $NetBSD: Makefile,v 1.47 2007/01/04 11:29:07 rillig Exp $

DISTNAME=	anjuta-2.0.2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=anjuta/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.anjuta.org/
COMMENT=	Gnome based IDE for C and C++

DEPENDS+=	autogen-[0-9]*:../../devel/autogen
DEPENDS+=	autoconf>=2.59:../../devel/autoconf
DEPENDS+=	automake>=1.8.2:../../devel/automake
DEPENDS+=	glade>=2.6.0:../../devel/glade
DEPENDS+=	gnome2-terminal>=2.4.2:../../x11/gnome2-terminal
DEPENDS+=	libtool>=1.5.2:../../devel/libtool
DEPENDS+=	yelp>=2.4.2:../../misc/yelp

BUILD_DEPENDS+=		p5-XML-Parser-[0-9]*:../../textproc/p5-XML-Parser

USE_DIRS+=		gnome2-1.5
USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake:run pkg-config:run msgfmt:run perl:run sh:run
GNU_CONFIGURE=		yes

SUBST_CLASSES+=		unused
SUBST_STAGE.unused=	pre-configure
SUBST_MESSAGE.unused=	Fixing __unused__ occurrances to avoid name clash
SUBST_FILES.unused=	tagmanager/c.c tagmanager/ctags.c tagmanager/general.h
SUBST_FILES.unused+=	tagmanager/lua.c tagmanager/options.c tagmanager/parse.c
SUBST_FILES.unused+=	tagmanager/parse.h tagmanager/regex.c
SUBST_FILES.unused+=	tagmanager/tm_file_entry.c tagmanager/tm_project.c
SUBST_FILES.unused+=	tagmanager/tm_source_file.c tagmanager/tm_workspace.c
SUBST_SED.unused=	-e 's/__unused__/_exctags_unused_/g'

REPLACE_SH+=		scripts/anjuta_import.sh.in
REPLACE_PERL+=		plugins/tools/scripts/*.pl

.include "../../devel/devhelp/buildlink3.mk"
.include "../../devel/gdl/buildlink3.mk"
.include "../../devel/gnome-build/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../devel/pcre/buildlink3.mk"
.include "../../devel/subversion-base/buildlink3.mk"
.include "../../graphics/graphviz/buildlink3.mk"
.include "../../print/libgnomeprintui/buildlink3.mk"
.include "../../textproc/scrollkeeper/omf.mk"
.include "../../x11/gtksourceview/buildlink3.mk"
.include "../../x11/vte/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
