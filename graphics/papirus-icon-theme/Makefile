# $NetBSD: Makefile,v 1.10 2021/01/13 18:26:23 jperkin Exp $

DISTNAME=	papirus-icon-theme-20200301
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=PapirusDevelopmentTeam/}
GITHUB_PROJECT=	papirus-icon-theme
GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	nia@NetBSD.org
HOMEPAGE=	https://github.com/PapirusDevelopmentTeam/papirus-icon-theme
COMMENT=	SVG icon theme based on the Paper Icon Set
LICENSE=	gnu-gpl-v3

EXTRACT_USING=	bsdtar
USE_TOOLS+=	gmake
ICON_THEMES=	yes

#
# This package installs over 750,000 files.  While dynamic PLISTs are to be
# avoided where possible, trying to maintain a static PLIST for this many
# files is impractical and would bloat the repository considerably.
#
# The install script is literally just "cp -R <list of dirs>", so there is
# hopefully little to go wrong and result in a broken package.
#
CHECK_FILES=		no
GENERATE_PLIST=		cd ${DESTDIR}${PREFIX};
GENERATE_PLIST+=	${FIND} share \( -type f -o -type l \) | ${SORT};

# Save some time...
CHECK_INTERPRETER_SKIP+=	share/icons/*/*/*/*.svg
CHECK_SHLIBS_SUPPORTED=		no
CHECK_SSP_SUPPORTED=		no
CHECK_WRKREF_SKIP+=		share/icons/*/*/*/*.svg

.include "../../graphics/gnome-icon-theme/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
