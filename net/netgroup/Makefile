# $NetBSD: Makefile,v 1.4 2010/02/11 22:17:29 joerg Exp $
#

DISTNAME=	netgroup-0.0
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.astron.com/pub/netgroup/

MAINTAINER=	christos@NetBSD.org
COMMENT=	Netgroup membership listing and testing functions

PKG_DESTDIR_SUPPORT=	user-destdir

NOT_FOR_PLATFORM=	Interix-*-* # no netgroups

INSTALLATION_DIRS+=	bin ${PKGMANDIR}/man1
INSTALL_TARGET=	inst-all
INSTALL_MAKE_FLAGS+=	BINDIR=${DESTDIR}${PREFIX}/bin \
			MANDIR=${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
