# $NetBSD: Makefile,v 1.4 2003/07/21 17:24:37 martti Exp $
#

DISTNAME=		sux-1.0
CATEGORIES=		sysutils
MASTER_SITES=		ftp://ftp.gw.com/pub/people/kim/

MAINTAINER=		kim@tac.nyc.ny.us
COMMENT=		Set user id, preserving shell and environment, checking ssh agent

DEPENDS+=		osname-[0-9]*:../../sysutils/osname
DEPENDS+=		sshsh-[0-9]*:../../sysutils/sshsh

NO_CONFIGURE=		yes
ALL_TARGET=		all PREFIX=${PREFIX}
INSTALL_TARGET=		install PREFIX=${PREFIX}

.include "../../mk/bsd.pkg.mk"
