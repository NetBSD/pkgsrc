# $NetBSD: Makefile,v 1.17 2014/10/09 14:06:03 wiz Exp $
#

DISTNAME=	chef-19920415
CATEGORIES=	converters
MASTER_SITES=	http://www.evolutionzone.com/kulturezone/c-g.writing/
DISTFILES=	chef.l.txt

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	none
COMMENT=	Convert from English to (mock) Swedish - Bork Bork Bork!

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
	${INSTALL_PROGRAM} ${WRKSRC}/chef ${DESTDIR}${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
