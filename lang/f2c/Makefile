# $NetBSD: Makefile,v 1.5 1999/01/14 13:56:04 frueauf Exp $

DISTNAME=	f2c-19980913
WRKSRC=		${WRKDIR}/f2c
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_LOCAL}

MAINTAINER=	mcmahill@alum.mit.edu
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
