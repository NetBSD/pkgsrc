# $NetBSD: Makefile,v 1.8 2025/04/21 21:06:36 wiz Exp $

DISTNAME=	netgroup-0.0
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.astron.com/pub/netgroup/

MAINTAINER=	christos@NetBSD.org
COMMENT=	Netgroup membership listing and testing functions

USE_FEATURES+=		cdefs

INSTALLATION_DIRS+=	bin ${PKGMANDIR}/man1
INSTALL_TARGET=		inst-all
INSTALL_MAKE_FLAGS+=	BINDIR=${DESTDIR}${PREFIX}/bin \
			MANDIR=${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
