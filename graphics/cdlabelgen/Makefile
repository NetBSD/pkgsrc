# $NetBSD: Makefile,v 1.21 2008/06/20 01:09:21 joerg Exp $

DISTNAME=	cdlabelgen-3.6.0
CATEGORIES=	graphics
MASTER_SITES=	http://www.aczoom.com/pub/tools/
EXTRACT_SUFX=	.tgz

MAINTAINER=	cube@NetBSD.org
HOMEPAGE=	http://www.aczoom.com/tools/cdinsert/
COMMENT=	Generate frontcards and traycards for CDs

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=	perl:run
USE_LANGUAGES=	# empty

MAKE_ENV+=	SED=${SED:Q}
MAKE_ENV+=	MV=${MV:Q}

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

post-extract:
	cd ${WRKSRC} && ${CHMOD} go+r *

.include "../../mk/bsd.pkg.mk"
