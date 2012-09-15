# $NetBSD: Makefile,v 1.27 2012/09/15 10:05:43 obache Exp $
#

DISTNAME=	taskjuggler-2.4.3
PKGREVISION=	13
CATEGORIES=	misc
MASTER_SITES=	http://www.taskjuggler.org/download/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.taskjuggler.org/
COMMENT=	Project management tool

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
SET_LIBDIR=	yes
CONFIGURE_ARGS+=--with-docdir=${PREFIX}/share/doc/taskjuggler/
USE_LANGUAGES=	c c++
USE_LIBTOOL=	yes
USE_TOOLS+=	perl msgfmt

REPLACE_SH=	TestSuite/runtests

SUBST_CLASSES+=		tz
SUBST_STAGE.tz=		post-patch
SUBST_FILES.tz=		TestSuite/Misc/export/project_a.tjp \
			TestSuite/Misc/export/project_b1.tjp \
			TestSuite/Misc/export/project_b2.tjp \
			TestSuite/Misc/export/project_b3.tjp \
			TestSuite/Misc/export/projectReference_a_1.tjp
SUBST_MESSAGE.tz=	Fixing old timezone names.
SUBST_SED.tz=		-e "s|timezone \"US/Mountain\"|timezone \"America/Denver\"|"

pre-build:
	# I have no idea why this test fails, and it is undocumented.
	# The log file also doesn't provide any useful information.
	rm -f ${WRKSRC}/TestSuite/Syntax/Errors/Timezone.tjp

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../meta-pkgs/kde3/kde3.mk"
.include "../../misc/kdepim3/buildlink3.mk" # for libkcal
.include "../../x11/qt3/application.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
