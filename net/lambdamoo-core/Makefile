# $NetBSD: Makefile,v 1.6 2004/01/20 12:22:19 agc Exp $

DISTNAME=	LambdaCore-12Apr99.db
PKGNAME=	lambdamoo-core-990412
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.lambda.moo.mud.org/pub/MOO/ \
		ftp://ftp.kanga.nu/pub/mirrors/ftp.lambda.moo.mud.org/pub/MOO/
EXTRACT_SUFX=	.gz

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.ccs.neu.edu/home/eostrom/muds/lambdamoo.html
COMMENT=	Generic core classes for lambdamoo

EXTRACT_CMD=	:

WRKSRC=		${WRKDIR}

post-extract:
	${CP} ${DISTDIR}/${DISTFILES} ${WRKSRC}
	${GUNZIP_CMD} ${WRKSRC}/${DISTFILES}

do-build:

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/lambdamoo
	${INSTALL_DATA} ${WRKSRC}/${DISTNAME} ${PREFIX}/share/lambdamoo

.include "../../mk/bsd.pkg.mk"
