# $NetBSD: Makefile,v 1.5 2000/03/20 07:26:23 tron Exp $

DISTNAME=	vpn-1.0
PKGNAME=	ssh-ip-tunnel-1.0
CATEGORIES=	security net
MASTER_SITES=	http://bleu.west.spy.net/~dustin/soft/

MAINTAINER=	dustin@spy.net

DEPENDS+=	pty-redir-0.1:../../misc/pty-redir
DEPENDS+=	ssh{-1.2.27,6-1.2.27}:../../security/ssh

CONFLICTS=	vpn-1.0

GNU_CONFIGURE=	YES

.include "../../mk/bsd.pkg.mk"
