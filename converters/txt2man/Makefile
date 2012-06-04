# $NetBSD: Makefile,v 1.10 2012/06/04 12:16:05 obache Exp $
#

DISTNAME=	txt2man-1.5.6
CATEGORIES=	converters
MASTER_SITES=	http://mvertes.free.fr/download/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://mvertes.free.fr/
COMMENT=	Convert flat ASCII text to man page format
LICENSE=	gnu-gpl-v2 # or later

PKG_DESTDIR_SUPPORT=	user-destdir

NO_BUILD=	YES
USE_TOOLS+=	gawk

INSTALL_MAKE_FLAGS+=	prefix=${DESTDIR}${PREFIX}

.include "../../mk/bsd.pkg.mk"
