# $NetBSD: Makefile,v 1.5 2009/10/29 21:34:12 tnn Exp $
#

DISTNAME=		genpasswd-1.5
CATEGORIES=		sysutils
MASTER_SITES=		ftp://ftp.gw.com/pub/people/kim/

MAINTAINER=		kim@tac.nyc.ny.us
COMMENT=		Random password generator

PKG_DESTDIR_SUPPORT=	user-destdir

NO_CONFIGURE=		yes
INSTALL_TARGET=		install install.man		\
			  DEST=${DESTDIR}${PREFIX}	\
			  MANDIR=${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

INSTALLATION_DIRS+=	bin ${PKGMANDIR}/man1

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Darwin"
BUILD_TARGET=	gcc
.endif

.include "../../mk/bsd.pkg.mk"
