# $NetBSD: Makefile,v 1.2 1999/05/26 22:45:11 tron Exp $

DISTNAME=	pty-redir-0.1
CATEGORIES=	misc
MASTER_SITES=	ftp://ftp.vein.hu/pub/ssa/contrib/mag/ \
		http://bleu.west.spy.net/~dustin/soft/

MAINTAINER=	dustin@spy.net

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pty-redir ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
