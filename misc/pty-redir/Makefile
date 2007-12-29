# $NetBSD: Makefile,v 1.6 2007/12/29 16:02:53 obache Exp $

DISTNAME=	pty-redir-0.1
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_BACKUP} \
		ftp://ftp.vein.hu/pub/ssa/contrib/mag/ \
		http://bleu.west.spy.net/~dustin/soft/

MAINTAINER=	dustin@spy.net
COMMENT=	Attach a program's stdio to a pty

INSTALLATION_DIRS=	bin

PKG_DESTDIR_SUPPORT=	user-destdir

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pty-redir ${DESTDIR}${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
