# $NetBSD: Makefile,v 1.23 2009/06/09 19:10:34 wiz Exp $

DISTNAME=	guile-www-2.24
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
