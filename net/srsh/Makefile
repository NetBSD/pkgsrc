# $NetBSD: Makefile,v 1.7 2001/09/27 23:18:32 jlam Exp $
#

DISTNAME=		srsh-1.2
CATEGORIES=		net
MASTER_SITES=		ftp://ftp.gw.com/pub/people/kim/

MAINTAINER=		kim@tac.nyc.ny.us
COMMENT=		emulate rsh client behavior using ssh

.if !exists(/usr/bin/ssh)
DEPENDS+=		{ssh{,6}-[0-9]*,openssh-[0-9]*}:../../security/ssh
.endif

NO_CONFIGURE=		yes
ALL_TARGET=		all PREFIX=${PREFIX}
INSTALL_TARGET=		install PREFIX=${PREFIX}

.include "../../mk/bsd.pkg.mk"
