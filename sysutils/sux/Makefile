# $NetBSD: Makefile,v 1.2 2001/02/17 17:42:18 wiz Exp $
#

DISTNAME=		sux-1.0
CATEGORIES=		sysutils
MASTER_SITES=		ftp://ftp.gw.com/pub/people/kim/

MAINTAINER=		kim@tac.nyc.ny.us
COMMENT=		set user id, preserving shell and environment, checking ssh agent

DEPENDS+=		osname-*:../../sysutils/osname
DEPENDS+=		sshsh-*:../../sysutils/sshsh

NO_CONFIGURE=		yes
ALL_TARGET=		all PREFIX=${PREFIX}
INSTALL_TARGET=		install PREFIX=${PREFIX}

.include "../../mk/bsd.pkg.mk"
