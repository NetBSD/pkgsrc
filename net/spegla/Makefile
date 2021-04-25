# $NetBSD: Makefile,v 1.11 2021/04/25 06:47:52 wiz Exp $

DISTNAME=		spegla-1.1p4
PKGREVISION=		1
CATEGORIES=		net
#MASTER_SITES=		ftp://subzero.campus.luth.se/pub/spegla/

MAINTAINER=		jnilsson@ludd.luth.se
COMMENT=		Mirror program for FTP sites (written in C)

BUILDLINK_TRANSFORM+=	rm:-Werror

USE_BSD_MAKEFILE=	yes
INSTALL_MAKE_FLAGS+=	MANDIR=${PREFIX:Q}/${PKGMANDIR:Q}

INSTALLATION_DIRS=	bin ${PKGMANDIR}/cat1 ${PKGMANDIR}/man1 \
			share/examples/spegla

.include "../../mk/bsd.pkg.mk"
