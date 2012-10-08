# $NetBSD: Makefile,v 1.8 2012/10/08 09:57:35 asau Exp $

DISTNAME=	pty-redir-0.1
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_BACKUP} \
		http://bleu.west.spy.net/~dustin/soft/

MAINTAINER=	dustin@spy.net
COMMENT=	Attach a program's stdio to a pty

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pty-redir ${DESTDIR}${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
