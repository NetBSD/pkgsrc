# $NetBSD: Makefile,v 1.7 2010/01/27 20:16:56 joerg Exp $
#

DISTNAME=		sux-1.0
CATEGORIES=		sysutils
MASTER_SITES=		ftp://ftp.gw.com/pub/people/kim/

MAINTAINER=		kim@tac.nyc.ny.us
COMMENT=		Set user id, preserving shell and environment, checking ssh agent

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=		osname-[0-9]*:../../sysutils/osname
DEPENDS+=		sshsh-[0-9]*:../../sysutils/sshsh

NO_CONFIGURE=		yes
MAKE_FLAGS+=		PREFIX=${DESTDIR}${PREFIX}

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
