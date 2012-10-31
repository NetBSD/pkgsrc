# $NetBSD: Makefile,v 1.2 2012/10/31 11:17:10 asau Exp $

PKGNAME=	lemon-1.0
DISTNAME=	sqlite-3.5.9
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://www.hwaci.com/sw/sqlite/ \
		http://www.sqlite.org/

MAINTAINER=	airhead@users.sf.net
HOMEPAGE=	http://www.hwaci.com/sw/lemon/
COMMENT=	Simple LALR(1) parser generator

WRKSRC=		${WRKDIR}/${DISTNAME}/tool

INSTALLATION_DIRS=	bin share/lemon

SUBST_CLASSES+=		paths
SUBST_FILES.paths=	lemon.c
SUBST_SED.paths+=	-e 's,"lempar.c","${PREFIX}/share/lemon/lempar.c",g'
SUBST_STAGE.paths=	post-patch

do-build:
	cd ${WRKSRC} && ${CC} ${CFLAGS} lemon.c -o lemon

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/lemon ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/lempar.c ${DESTDIR}${PREFIX}/share/lemon

.include "../../mk/bsd.pkg.mk"
