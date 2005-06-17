# $NetBSD: Makefile,v 1.5 2005/06/17 03:50:22 jlam Exp $

DISTNAME=	pty-redir-0.1
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_BACKUP} \
		ftp://ftp.vein.hu/pub/ssa/contrib/mag/ \
		http://bleu.west.spy.net/~dustin/soft/

MAINTAINER=	dustin@spy.net
COMMENT=	Attach a program's stdio to a pty

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pty-redir ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
