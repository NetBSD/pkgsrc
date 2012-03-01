# $NetBSD: Makefile,v 1.10 2012/03/01 16:27:57 hans Exp $
#

DISTNAME=	destroy-20040415
CATEGORIES=	security
MASTER_SITES=	http://www.impurity.org/mirrors/destroy/

MAINTAINER=	shane@freebsdhackers.net
HOMEPAGE=	http://www.freebsdhackers.net/destroy/
COMMENT=	Program to securely destroy files on the hard disk

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1
PKG_DESTDIR_SUPPORT=	user-destdir

USE_FEATURES+=	fts_open

MAKE_ENV+=	CPPFLAGS=${CPPFLAGS:Q} LIBS=${LIBS:Q}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/destroy ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/destroy.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
