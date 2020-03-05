# $NetBSD: Makefile,v 1.1 2020/03/05 14:14:27 nia Exp $

DISTNAME=	comic-neue-2.3
CATEGORIES=	fonts
MASTER_SITES=	http://www.comicneue.com/
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.comicneue.com/
COMMENT=	Font that fixes the shortcomings of Comic Sans
LICENSE=	ofl-v1.1

WRKSRC=		${WRKDIR}

post-install:
	${FIND} ${DESTDIR}${PREFIX} -name '.*' -print0 | ${XARGS} -0 rm -f

.include "../../mk/fonts.mk"
.include "../../mk/bsd.pkg.mk"
