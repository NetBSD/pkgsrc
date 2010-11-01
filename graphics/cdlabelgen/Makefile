# $NetBSD: Makefile,v 1.22 2010/11/01 00:08:11 wiz Exp $

DISTNAME=	cdlabelgen-3.6.0
CATEGORIES=	graphics
MASTER_SITES=	http://www.aczoom.com/pub/tools/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
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
