# $NetBSD: Makefile,v 1.4 2000/10/10 15:02:13 dmcmahill Exp $
#

DISTNAME=		srsh-1.2
CATEGORIES=		net
MASTER_SITES=		ftp://ftp.gw.com/pub/people/kim/

MAINTAINER=		kim@tac.nyc.ny.us

.if !exists(/usr/bin/ssh)
DEPENDS+=		ssh{,6}-*:../../security/ssh
.endif

NO_CONFIGURE=		yes
ALL_TARGET=		all PREFIX=${PREFIX}
INSTALL_TARGET=		install PREFIX=${PREFIX}

.include "../../mk/bsd.pkg.mk"
