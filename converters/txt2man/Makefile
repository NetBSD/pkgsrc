# $NetBSD: Makefile,v 1.11 2012/10/03 00:20:18 asau Exp $
#

DISTNAME=	txt2man-1.5.6
CATEGORIES=	converters
MASTER_SITES=	http://mvertes.free.fr/download/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://mvertes.free.fr/
COMMENT=	Convert flat ASCII text to man page format
LICENSE=	gnu-gpl-v2 # or later

NO_BUILD=	YES
USE_TOOLS+=	gawk

INSTALL_MAKE_FLAGS+=	prefix=${DESTDIR}${PREFIX}

.include "../../mk/bsd.pkg.mk"
