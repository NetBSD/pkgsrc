# $NetBSD: Makefile,v 1.7 2012/10/23 19:51:03 asau Exp $
#

DISTNAME=		genpasswd-1.5
CATEGORIES=		sysutils
MASTER_SITES=		# ftp://ftp.gw.com/pub/people/kim/

MAINTAINER=		kim@tac.nyc.ny.us
COMMENT=		Random password generator

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
