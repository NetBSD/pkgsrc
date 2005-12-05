# $NetBSD: Makefile,v 1.14 2005/12/05 20:49:49 rillig Exp $
#

DISTNAME=	nspmod-0.1
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SUNSITE:=apps/sound/players/}

MAINTAINER=	mycroft@NetBSD.org
#HOMEPAGE=	http://www.jeton.or.jp/users/toru/www/orgsoft/index.html
COMMENT=	MOD/S3M/MTM tracker that does its own DSP, uses VoxWare v2.90+

NOT_FOR_PLATFORM=	Interix-*-*

PKG_INSTALLATION_TYPES=	overwrite pkgviews

INSTALLATION_DIRS=	bin man/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/nspmod ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/nspmod.1 ${PREFIX}/man/man1

.include "../../mk/bsd.pkg.mk"
