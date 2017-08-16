# $NetBSD: Makefile,v 1.15 2017/08/16 20:21:13 wiz Exp $

DISTNAME=	LambdaCore-12Apr99.db
PKGNAME=	lambdamoo-core-990412
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=lambdamoo/}
MASTER_SITES+=	ftp://ftp.kanga.nu/pub/mirrors/ftp.lambda.moo.mud.org/pub/MOO/
EXTRACT_SUFX=	.gz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://sourceforge.net/projects/lambdamoo/
COMMENT=	Generic core classes for lambdamoo

USE_TOOLS+=	gunzip

WRKSRC=		${WRKDIR}

NO_BUILD=	yes

INSTALLATION_DIRS+=	share/lambdamoo

do-install:
	${INSTALL_DATA} ${WRKSRC}/${DISTNAME} ${DESTDIR}${PREFIX}/share/lambdamoo

.include "../../mk/bsd.pkg.mk"
