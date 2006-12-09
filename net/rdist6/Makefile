# $NetBSD: Makefile,v 1.16 2006/12/09 02:18:22 markd Exp $
#

DISTNAME=	freerdist-0.92
PKGREVISION=	2
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.astron.com/pub/freerdist/ \
		ftp://ftp.gw.com/pub/unix/freerdist/

MAINTAINER=	christos@NetBSD.org
COMMENT=	Network file distribution/synchronisation utility

USE_TOOLS+=	byacc

RDIST6_NAME=	rdist6

INSTALL_TARGET=	install install.man
MAKE_ENV+=	RDIST6_NAME=${RDIST6_NAME:Q}

CONFLICTS=	rdist6-[0-9]*

post-extract:
	${CP} ${FILESDIR}/os-dragonfly.h ${WRKSRC}/config
	${ECHO} LIB_SYS=-lcompat > ${WRKSRC}/config/mf.dragonfly

post-install:
	@strip ${PREFIX}/bin/${RDIST6_NAME}
	@strip ${PREFIX}/bin/rdistd

.include "../../mk/bsd.pkg.mk"
