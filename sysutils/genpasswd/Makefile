# $NetBSD: Makefile,v 1.11 2023/12/19 17:23:13 zafer Exp $
#

DISTNAME=		genpasswd-1.5
CATEGORIES=		sysutils
MASTER_SITES=		https://software.kimmo.suominen.com/

MAINTAINER=		pkgsrc-users@NetBSD.org
COMMENT=		Random password generator

NO_CONFIGURE=		yes
INSTALL_TARGET=		install install.man		\
			  DEST=${DESTDIR}${PREFIX}	\
			  MANDIR=${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

INSTALLATION_DIRS+=	bin ${PKGMANDIR}/man1

BUILD_TARGET.Darwin=	gcc

.include "../../mk/bsd.pkg.mk"
