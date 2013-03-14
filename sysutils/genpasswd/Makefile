# $NetBSD: Makefile,v 1.8 2013/03/14 14:19:52 kim Exp $
#

DISTNAME=		genpasswd-1.5
CATEGORIES=		sysutils
MASTER_SITES=		http://oss.gw.com/people/kim/

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
