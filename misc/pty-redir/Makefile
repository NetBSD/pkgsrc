# $NetBSD: Makefile,v 1.3 2001/02/17 18:09:20 wiz Exp $

DISTNAME=	pty-redir-0.1
CATEGORIES=	misc
MASTER_SITES=	ftp://ftp.vein.hu/pub/ssa/contrib/mag/ \
		http://bleu.west.spy.net/~dustin/soft/

MAINTAINER=	dustin@spy.net
COMMENT=	Attach a program's stdio to a pty

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pty-redir ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
