# $NetBSD: Makefile,v 1.9 2004/05/31 22:13:16 kristerw Exp $
#

DISTNAME=		srsh-1.2
CATEGORIES=		net
MASTER_SITES=		ftp://ftp.gw.com/pub/people/kim/

MAINTAINER=		kim@tac.nyc.ny.us
COMMENT=		Emulate rsh client behavior using ssh

.if !exists(/usr/bin/ssh)
DEPENDS+=		{ssh{,6}-[0-9]*,openssh-[0-9]*}:../../security/openssh
.endif

NO_CONFIGURE=		yes
ALL_TARGET=		all PREFIX=${PREFIX}
INSTALL_TARGET=		install PREFIX=${PREFIX}

.include "../../mk/bsd.pkg.mk"
