# Makefile for:		nspmod
# Version required:	0.1
#
# $NetBSD: Makefile,v 1.3 1998/03/20 06:41:17 mycroft Exp $
#

DISTNAME=	nspmod-0.1
CATEGORIES=	audio
MASTER_SITES=	http://www.jeton.or.jp/users/toru/www/orgsoft/nspmod/	\
		${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	apps/sound/players

MAINTAINER=	mycroft@NetBSD.ORG

MAN1=		nspmod.1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/nspmod ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/nspmod.1 ${MANPREFIX}/man/man1

.include <bsd.port.mk>
