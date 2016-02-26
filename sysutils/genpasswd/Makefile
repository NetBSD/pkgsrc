# $NetBSD: Makefile,v 1.9 2016/02/26 10:24:12 jperkin Exp $
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

BUILD_TARGET.Darwin=	gcc

.include "../../mk/bsd.pkg.mk"
