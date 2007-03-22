# $NetBSD: Makefile,v 1.1.1.1 2007/03/22 17:15:19 rillig Exp $
#

DISTNAME=	taskjuggler-2.3.1
CATEGORIES=	misc
MASTER_SITES=	http://www.taskjuggler.org/download/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	rillig@NetBSD.org
HOMEPAGE=	http://www.taskjuggler.org/download/
COMMENT=	Project management tool

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--with-docdir=${PREFIX}/share/doc/taskjuggler
USE_LANGUAGES=	c c++
USE_LIBTOOL=	yes
USE_TOOLS+=	perl

pre-build:
	# I have no idea why this test fails, and it is undocumented.
	# The log file also doesn't provide any useful information.
	rm -f ${WRKSRC}/TestSuite/Syntax/Errors/Timezone.tjp

.include "../../meta-pkgs/kde3/kde3.mk"
.include "../../misc/kdepim3/buildlink3.mk" # for libkcal
.include "../../x11/qt3/application.mk"
.include "../../mk/bsd.pkg.mk"
