# New ports collection makefile for:	nspmod-0.1
# Version required:			0.1
# Date created:				1 Jun 1997
# Whom:					jmg
#
# $NetBSD: Makefile,v 1.2 1997/10/31 22:08:37 augustss Exp $
# FreeBSD Id: Makefile,v 1.2 1997/06/03 08:54:55 asami Exp 
#

DISTNAME=	nspmod-0.1
CATEGORIES=	audio
MASTER_SITES=	http://www.jeton.or.jp/users/toru/www/orgsoft/nspmod/	\
		${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	apps/sound/players

# FreeBSD maintainer
MAINTAINER=	jmg@FreeBSD.ORG

MAN1=		nspmod.1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/nspmod ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/nspmod.1 ${MANPREFIX}/man/man1

.include <bsd.port.mk>
