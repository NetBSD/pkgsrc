# $NetBSD: Makefile,v 1.3 2011/09/05 20:20:27 cheusov Exp $
#

DISTNAME=	aamath-0.3
PKGREVISION=	1
CATEGORIES=	math
MASTER_SITES=	http://fuse.superglue.se/aamath/

MAINTAINER=	esg@sdf.lonestar.org
HOMEPAGE=	http://fuse.superglue.se/aamath/
COMMENT=	ASCII art mathematics

PKG_DESTDIR_SUPPORT=	user-destdir
INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

WRKSRC=		${WRKDIR}/aamath
USE_LANGUAGES=	c++
MAKE_JOBS_SAFE=	no

USE_TOOLS=	yacc lex

BUILD_TARGET=	aamath

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/aamath ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/aamath.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../devel/readline/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
