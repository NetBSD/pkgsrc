# $NetBSD: Makefile,v 1.14 2004/05/31 22:13:16 kristerw Exp $

DISTNAME=	vpn-1.0
PKGNAME=	ssh-ip-tunnel-1.0
CATEGORIES=	security net
MASTER_SITES=	http://bleu.west.spy.net/~dustin/soft/

MAINTAINER=	dustin@spy.net
COMMENT=	Simple VPN system using pppd over ssh

DEPENDS+=	pty-redir-0.1:../../misc/pty-redir
.if !exists(/usr/bin/ssh)
DEPENDS+=	{openssh-[0-9]*,ssh{,6}-1.2.27*}:../../security/openssh
.endif

CONFLICTS=	vpn-1.0

GNU_CONFIGURE=	YES

.include "../../mk/bsd.pkg.mk"
