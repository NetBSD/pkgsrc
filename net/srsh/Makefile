# $NetBSD: Makefile,v 1.6 2001/02/17 18:19:41 wiz Exp $
#

DISTNAME=		srsh-1.2
CATEGORIES=		net
MASTER_SITES=		ftp://ftp.gw.com/pub/people/kim/

MAINTAINER=		kim@tac.nyc.ny.us
COMMENT=		emulate rsh client behavior using ssh

.if !exists(/usr/bin/ssh)
DEPENDS+=		{ssh{,6}-*,openssh-*}:../../security/ssh
.endif

NO_CONFIGURE=		yes
ALL_TARGET=		all PREFIX=${PREFIX}
INSTALL_TARGET=		install PREFIX=${PREFIX}

.include "../../mk/bsd.pkg.mk"
