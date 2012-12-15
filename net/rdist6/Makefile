# $NetBSD: Makefile,v 1.25 2012/12/15 21:40:33 markd Exp $
#

DISTNAME=	freerdist-0.94
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.astron.com/pub/freerdist/

MAINTAINER=	christos@NetBSD.org
COMMENT=	Network file distribution/synchronisation utility

USE_TOOLS+=	byacc

RDIST6_NAME=	rdist6

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1 ${PKGMANDIR}/man8
INSTALL_TARGET=	install install.man
MAKE_ENV+=	RDIST6_NAME=${RDIST6_NAME:Q}

CONFLICTS=	rdist6-[0-9]*

.include "../../mk/bsd.pkg.mk"
