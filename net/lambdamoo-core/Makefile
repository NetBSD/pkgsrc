# $NetBSD: Makefile,v 1.2 2003/03/29 12:41:58 jmmv Exp $

DISTNAME=	LambdaCore-12Apr99.db
PKGNAME=	lambdamoo-core-990412
WRKSRC=		${WRKDIR}
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.lambda.moo.mud.org/pub/MOO/ \
		ftp://ftp.kanga.nu/pub/mirrors/ftp.lambda.moo.mud.org/pub/MOO/
EXTRACT_SUFX=	.gz

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.ccs.neu.edu/home/eostrom/muds/lambdamoo.html
COMMENT=	generic core classes for lambdamoo

EXTRACT_CMD=	:

post-extract:
	${CP} ${DISTDIR}/${DISTFILES} ${WRKSRC}
	${GUNZIP_CMD} ${WRKSRC}/${DISTFILES}

do-build:

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/lambdamoo
	${INSTALL_DATA} ${WRKSRC}/${DISTNAME} ${PREFIX}/share/lambdamoo

.include "../../mk/bsd.pkg.mk"
