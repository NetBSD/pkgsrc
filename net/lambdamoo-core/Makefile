# $NetBSD: Makefile,v 1.9 2006/01/21 18:57:41 jlam Exp $

DISTNAME=	LambdaCore-12Apr99.db
PKGNAME=	lambdamoo-core-990412
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.lambda.moo.mud.org/pub/MOO/ \
		ftp://ftp.kanga.nu/pub/mirrors/ftp.lambda.moo.mud.org/pub/MOO/
EXTRACT_SUFX=	.gz

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.ccs.neu.edu/home/eostrom/muds/lambdamoo.html
COMMENT=	Generic core classes for lambdamoo

USE_TOOLS+=	gunzip

WRKSRC=		${WRKDIR}

do-build:

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/lambdamoo
	${INSTALL_DATA} ${WRKSRC}/${DISTNAME} ${PREFIX}/share/lambdamoo

.include "../../mk/bsd.pkg.mk"
