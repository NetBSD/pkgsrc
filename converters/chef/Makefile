# $NetBSD: Makefile,v 1.2 2003/12/24 09:53:48 jmmv Exp $
#

DISTNAME=	chef.l
PKGNAME=	chef-19920415
CATEGORIES=	converters
MASTER_SITES=	http://www.evolutionzone.com/kulturezone/c-g.writing/
EXTRACT_SUFX=	.txt

MAINTAINER=	tech-pkg@NetBSD.org
#HOMEPAGE=	none
COMMENT=	Convert from English to (mock) Swedish - Bork Bork Bork!

WRKSRC=		${WRKDIR}

MAKE_ENV+=	BINDIR=${PREFIX}/bin

do-extract:
	${CP} ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX} ${WRKDIR}/chef.l
	${CP} ${FILESDIR}/Makefile ${WRKDIR}

.include "../../mk/bsd.pkg.mk"
