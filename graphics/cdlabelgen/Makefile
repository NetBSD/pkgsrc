# $NetBSD: Makefile,v 1.26 2013/02/16 08:56:45 shattered Exp $

DISTNAME=	cdlabelgen-4.2.0
#KGREVISION=	1
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
