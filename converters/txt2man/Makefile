# $NetBSD: Makefile,v 1.9 2010/01/29 16:53:09 joerg Exp $
#

DISTNAME=	txt2man-1.5.5
CATEGORIES=	converters
MASTER_SITES=	http://mvertes.free.fr/download/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://mvertes.free.fr/
COMMENT=	Convert flat ASCII text to man page format

PKG_DESTDIR_SUPPORT=	user-destdir

NO_BUILD=	YES
USE_TOOLS+=	gawk

INSTALL_MAKE_FLAGS+=	prefix=${DESTDIR}${PREFIX}

.include "../../mk/bsd.pkg.mk"
