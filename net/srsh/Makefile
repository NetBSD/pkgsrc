# $NetBSD: Makefile,v 1.5 2000/11/23 15:45:33 abs Exp $
#

DISTNAME=		srsh-1.2
CATEGORIES=		net
MASTER_SITES=		ftp://ftp.gw.com/pub/people/kim/

MAINTAINER=		kim@tac.nyc.ny.us

.if !exists(/usr/bin/ssh)
DEPENDS+=		{ssh{,6}-*,openssh-*}:../../security/ssh
.endif

NO_CONFIGURE=		yes
ALL_TARGET=		all PREFIX=${PREFIX}
INSTALL_TARGET=		install PREFIX=${PREFIX}

.include "../../mk/bsd.pkg.mk"
