# $NetBSD: Makefile,v 1.1.1.1 1999/08/30 17:46:32 kim Exp $
#

DISTNAME=		srsh-1.1
CATEGORIES=		net
MASTER_SITES=		ftp://ftp.gw.com/pub/people/kim/

MAINTAINER=		kim@tac.nyc.ny.us

DEPENDS+=		ssh-*:../../security/ssh

NO_CONFIGURE=		yes
ALL_TARGET=		all PREFIX=${PREFIX}
INSTALL_TARGET=		install PREFIX=${PREFIX}

.include "../../mk/bsd.pkg.mk"
