# $NetBSD: Makefile,v 1.7 1999/12/22 20:22:14 dmcmahill Exp $

DISTNAME=	f2c-19991025
PKGNAME=	f2c-19991025p1
WRKSRC=		${WRKDIR}/f2c
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_LOCAL}

MAINTAINER=	dmcmahill@netbsd.org
HOMEPAGE=	http://www.netlib.org/f2c/index.html

CONFLICTS=	egcs-current-19980608

post-extract::
	@rm ${WRKSRC}/index.html
	@gunzip ${WRKSRC}/*.gz
	@cd ${WRKSRC} ; sh libf77 ; sh libi77
	@rm ${WRKSRC}/src/index.html
	@mv ${WRKSRC}/src/.depend  ${WRKSRC}/src/depend.orig
	@gunzip ${WRKSRC}/src/*.gz

post-patch::
	@cd ${WRKSRC} ; ${CC} -o chktypes chktypes.c
	${WRKSRC}/chktypes
	@cp ${WRKSRC}/f2c.h ${WRKSRC}/libF77/f2c.h
	@cp ${WRKSRC}/f2c.h ${WRKSRC}/libI77/f2c.h

.include "../../mk/bsd.pkg.mk"
