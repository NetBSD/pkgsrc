# $NetBSD: Makefile,v 1.8 2000/01/09 01:19:09 wiz Exp $

DISTNAME=	f2c-19991025
PKGNAME=	f2c-19991025p1
WRKSRC=		${WRKDIR}/f2c
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_LOCAL}

MAINTAINER=	dmcmahill@netbsd.org
HOMEPAGE=	http://www.netlib.org/f2c/index.html

CONFLICTS=	egcs-current-19980608

post-extract::
	@${RM} ${WRKSRC}/index.html
	@${GUNZIP_CMD} ${WRKSRC}/*.gz
	@cd ${WRKSRC} ; ${SH} libf77 ; ${SH} libi77
	@${RM} ${WRKSRC}/src/index.html
	@${MV} ${WRKSRC}/src/.depend  ${WRKSRC}/src/depend.orig
	@${GUNZIP_CMD} ${WRKSRC}/src/*.gz

post-patch::
	@cd ${WRKSRC} ; ${CC} -o chktypes chktypes.c
	${WRKSRC}/chktypes
	@${CP} ${WRKSRC}/f2c.h ${WRKSRC}/libF77/f2c.h
	@${CP} ${WRKSRC}/f2c.h ${WRKSRC}/libI77/f2c.h

.include "../../mk/bsd.pkg.mk"
