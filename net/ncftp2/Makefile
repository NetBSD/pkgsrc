# New ports collection makefile for:    ncftp2
# Version required:     2.4.3
# Date created:         4 Nov 1994
# Whom:                 ache
#
# $NetBSD: Makefile,v 1.4 1998/03/23 19:29:38 tron Exp $
# $FreeBSD Id: Makefile,v 1.39 1998/01/31 17:49:48 jseger Exp
#

DISTNAME=       ncftp-2.4.3
CATEGORIES=	net
MASTER_SITES=   ftp://ftp.ncftp.com/ncftp/

MAINTAINER=	ache@FreeBSD.ORG

LIB_DEPENDS=	ncurses.3.4:${PORTSDIR}/devel/ncurses

GNU_CONFIGURE=  yes
CONFIGURE_ARGS+=	--disable-readline
MAN1=		ncftp2.1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ncftp ${PREFIX}/bin/ncftp2
	${INSTALL_MAN} ${WRKSRC}/ncftp.1 ${PREFIX}/man/man1/ncftp2.1

.include <bsd.port.mk>
