# $NetBSD: Makefile,v 1.7 2000/09/24 16:53:34 hubertf Exp $

DISTNAME=	vpn-1.0
PKGNAME=	ssh-ip-tunnel-1.0
CATEGORIES=	security net
MASTER_SITES=	http://bleu.west.spy.net/~dustin/soft/

MAINTAINER=	dustin@spy.net

DEPENDS+=	pty-redir-0.1:../../misc/pty-redir
DEPENDS+=	{openssh-*,ssh{,6}-1.2.27}:../../security/ssh

CONFLICTS=	vpn-1.0

GNU_CONFIGURE=	YES

.include "../../mk/bsd.pkg.mk"
