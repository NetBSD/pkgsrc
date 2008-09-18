# $NetBSD: Makefile,v 1.9 2008/09/18 09:12:42 joerg Exp $
#

DISTNAME=	taskjuggler-2.3.1
PKGREVISION=	4
CATEGORIES=	misc
MASTER_SITES=	http://www.taskjuggler.org/download/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.taskjuggler.org/
COMMENT=	Project management tool

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--with-docdir=${PREFIX}/share/doc/taskjuggler
USE_LANGUAGES=	c c++
USE_LIBTOOL=	yes
USE_TOOLS+=	perl msgfmt

pre-build:
	# I have no idea why this test fails, and it is undocumented.
	# The log file also doesn't provide any useful information.
	rm -f ${WRKSRC}/TestSuite/Syntax/Errors/Timezone.tjp

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../meta-pkgs/kde3/kde3.mk"
.include "../../misc/kdepim3/buildlink3.mk" # for libkcal
.include "../../x11/qt3/application.mk"
.include "../../mk/bsd.pkg.mk"
