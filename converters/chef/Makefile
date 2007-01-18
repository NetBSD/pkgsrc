# $NetBSD: Makefile,v 1.14 2007/01/18 11:51:33 rillig Exp $
#

DISTNAME=	chef-19920415
CATEGORIES=	converters
MASTER_SITES=	http://www.evolutionzone.com/kulturezone/c-g.writing/
DISTFILES=	chef.l.txt

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	none
COMMENT=	Convert from English to (mock) Swedish - Bork Bork Bork!

PKG_INSTALLATION_TYPES=	overwrite pkgviews

NO_CONFIGURE=	yes
USE_TOOLS+=	lex
WRKSRC=		${WRKDIR}
DIST_SUBDIR=	${PKGNAME_NOREV}

INSTALLATION_DIRS=	bin

do-extract:
	# deal with the dos encoding of the file
	cd ${WRKSRC} && tr '\r' '\n' < ${DISTDIR}/${DIST_SUBDIR}/${DISTFILES} > chef.l

do-build:
	cd ${WRKSRC} && lex chef.l
	${LINK.c} -o ${WRKSRC}/chef ${WRKSRC}/lex.yy.c -ll

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/chef ${PREFIX}/bin/

.include "../../mk/bsd.pkg.mk"
