# $NetBSD: Makefile,v 1.12 2001/02/17 17:50:10 wiz Exp $

DISTNAME=	vpn-1.0
PKGNAME=	ssh-ip-tunnel-1.0
CATEGORIES=	security net
MASTER_SITES=	http://bleu.west.spy.net/~dustin/soft/

MAINTAINER=	dustin@spy.net
COMMENT=	Simple VPN system using pppd over ssh

DEPENDS+=	pty-redir-0.1:../../misc/pty-redir
.if !exists(/usr/bin/ssh)
DEPENDS+=	{openssh-*,ssh{,6}-1.2.27*}:../../security/ssh
.endif

CONFLICTS=	vpn-1.0

GNU_CONFIGURE=	YES

.include "../../mk/bsd.pkg.mk"
