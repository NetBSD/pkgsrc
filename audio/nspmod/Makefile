# $NetBSD: Makefile,v 1.7 1998/08/20 15:16:39 tsarna Exp $
#

DISTNAME=	nspmod-0.1
CATEGORIES=	audio
MASTER_SITES=	http://www.jeton.or.jp/users/toru/www/orgsoft/nspmod/	\
		${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	apps/sound/players

MAINTAINER=	mycroft@NetBSD.ORG
HOMEPAGE=	http://www.jeton.or.jp/users/toru/www/orgsoft/index.html

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/nspmod ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/nspmod.1 ${PREFIX}/man/man1

.include "../../mk/bsd.pkg.mk"
