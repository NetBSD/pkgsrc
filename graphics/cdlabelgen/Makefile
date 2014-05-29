# $NetBSD: Makefile,v 1.28 2014/05/29 23:36:37 wiz Exp $

DISTNAME=	cdlabelgen-4.2.0
#KGREVISION=	1
PKGREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	http://www.aczoom.com/pub/tools/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.aczoom.com/tools/cdinsert/
COMMENT=	Generate frontcards and traycards for CDs

USE_TOOLS+=	perl:run perldoc
USE_LANGUAGES=	# empty
REPLACE_PERL+=	cdlabelgen

MAKE_ENV+=	SED=${SED:Q}
MAKE_ENV+=	MV=${MV:Q}

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

post-extract:
	cd ${WRKSRC} && ${CHMOD} go+r *

.include "../../mk/bsd.pkg.mk"
