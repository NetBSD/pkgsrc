# $NetBSD: Makefile,v 1.7 2019/11/03 11:45:44 rillig Exp $
#

DISTNAME=	netgroup-0.0
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.astron.com/pub/netgroup/

MAINTAINER=	christos@NetBSD.org
COMMENT=	Netgroup membership listing and testing functions

USE_FEATURES+=		cdefs

NOT_FOR_PLATFORM=	Interix-*-* # no netgroups

INSTALLATION_DIRS+=	bin ${PKGMANDIR}/man1
INSTALL_TARGET=		inst-all
INSTALL_MAKE_FLAGS+=	BINDIR=${DESTDIR}${PREFIX}/bin \
			MANDIR=${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
