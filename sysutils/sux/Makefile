# $NetBSD: Makefile,v 1.3 2001/09/27 23:18:44 jlam Exp $
#

DISTNAME=		sux-1.0
CATEGORIES=		sysutils
MASTER_SITES=		ftp://ftp.gw.com/pub/people/kim/

MAINTAINER=		kim@tac.nyc.ny.us
COMMENT=		set user id, preserving shell and environment, checking ssh agent

DEPENDS+=		osname-[0-9]*:../../sysutils/osname
DEPENDS+=		sshsh-[0-9]*:../../sysutils/sshsh

NO_CONFIGURE=		yes
ALL_TARGET=		all PREFIX=${PREFIX}
INSTALL_TARGET=		install PREFIX=${PREFIX}

.include "../../mk/bsd.pkg.mk"
