# $NetBSD: Makefile,v 1.4 2004/12/28 14:21:38 xtraeme Exp $

DISTNAME=	pty-redir-0.1
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_BACKUP} \
		ftp://ftp.vein.hu/pub/ssa/contrib/mag/ \
		http://bleu.west.spy.net/~dustin/soft/

MAINTAINER=	dustin@spy.net
COMMENT=	Attach a program's stdio to a pty

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pty-redir ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
