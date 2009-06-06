# $NetBSD: Makefile,v 1.18 2009/06/06 00:48:39 abs Exp $
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

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1 ${PKGMANDIR}/man8
INSTALL_TARGET=	install install.man
MAKE_ENV+=	RDIST6_NAME=${RDIST6_NAME:Q}

CONFLICTS=	rdist6-[0-9]*

PKG_DESTDIR_SUPPORT=	user-destdir

post-extract:
	${CP} ${FILESDIR}/os-dragonfly.h ${WRKSRC}/config
	${ECHO} LIB_SYS=-lcompat > ${WRKSRC}/config/mf.dragonfly

post-install:
	@strip ${DESTDIR}${PREFIX}/bin/${RDIST6_NAME}
	@strip ${DESTDIR}${PREFIX}/bin/rdistd

.include "../../mk/bsd.pkg.mk"
