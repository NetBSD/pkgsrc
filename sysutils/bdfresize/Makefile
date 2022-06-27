# $NetBSD: Makefile,v 1.2 2022/06/27 15:29:17 fcambus Exp $

DISTNAME=	bdfresize-1.5
CATEGORIES=	sysutils
MASTER_SITES=	https://www.distfiles.pl/

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Tool for resizing BDF format fonts
LICENSE=	gnu-gpl-v2

# Do not build embedded getopt
SUBST_CLASSES+=		makefile
SUBST_STAGE.makefile=	post-configure
SUBST_MESSAGE.makefile=	Do not build embedded getopt
SUBST_FILES.makefile=	Makefile
SUBST_SED.makefile+=	-e 's,charresize.o getopt.o,charresize.o,'

# Fix getopt includes
SUBST_CLASSES+=		includes
SUBST_STAGE.includes=	post-configure
SUBST_MESSAGE.includes=	Fix getopt includes
SUBST_FILES.includes=	bdfresize.c
SUBST_SED.includes+=	-e 's,"getopt.h",<getopt.h>,'

GNU_CONFIGURE=	yes

.include "../../mk/bsd.pkg.mk"
