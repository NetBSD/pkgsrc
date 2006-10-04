# $NetBSD: Makefile,v 1.11 2006/10/04 21:53:16 wiz Exp $

DISTNAME=	LambdaCore-12Apr99.db
PKGNAME=	lambdamoo-core-990412
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=lambdamoo/} \
		ftp://ftp.kanga.nu/pub/mirrors/ftp.lambda.moo.mud.org/pub/MOO/
EXTRACT_SUFX=	.gz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://sourceforge.net/projects/lambdamoo/
COMMENT=	Generic core classes for lambdamoo

USE_TOOLS+=	gunzip

WRKSRC=		${WRKDIR}

do-build:

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/lambdamoo
	${INSTALL_DATA} ${WRKSRC}/${DISTNAME} ${PREFIX}/share/lambdamoo

.include "../../mk/bsd.pkg.mk"
