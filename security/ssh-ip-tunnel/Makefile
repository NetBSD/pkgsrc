# $NetBSD: Makefile,v 1.8 2000/10/10 15:02:14 dmcmahill Exp $

DISTNAME=	vpn-1.0
PKGNAME=	ssh-ip-tunnel-1.0
CATEGORIES=	security net
MASTER_SITES=	http://bleu.west.spy.net/~dustin/soft/

MAINTAINER=	dustin@spy.net

DEPENDS+=	pty-redir-0.1:../../misc/pty-redir
.if !exists(/usr/bin/ssh)                 
DEPENDS+=	{openssh-*,ssh{,6}-1.2.27}:../../security/ssh
.endif

CONFLICTS=	vpn-1.0

GNU_CONFIGURE=	YES

.include "../../mk/bsd.pkg.mk"
