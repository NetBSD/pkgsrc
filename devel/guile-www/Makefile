# $NetBSD: Makefile,v 1.26 2010/03/24 19:43:23 asau Exp $

DISTNAME=	guile-www-2.25
PKGREVISION=	1
CATEGORIES=	devel www
MASTER_SITES=	http://www.gnuvola.org/software/guile-www/

MAINTAINER=	gdt@NetBSD.org
HOMEPAGE=	http://www.gnuvola.org/software/guile-www/
#Before ttn maintainership, formerly 1.1.1 at
#HOMEPAGE=	http://www.gnu.org/software/guile/
COMMENT=	Guile WWW module
LICENSE=	gnu-gpl-v3

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	YES
USE_TOOLS+=	gmake
INFO_FILES=	# PLIST

.include "../../lang/guile/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
