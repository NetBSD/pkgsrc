# $NetBSD: Makefile,v 1.1.1.1 2002/12/13 18:24:33 cjep Exp $
#

DISTNAME=	par-v1.0
PKGNAME=	parchive-1.0
CATEGORIES=	archivers
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=parchive/}

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://parchive.sourceforge.net/
COMMENT=	Parity Archiver

WRKSRC=		${WRKDIR}/par-cmdline-1.0
USE_BUILDLINK2=	YES
MAKE_FLAGS+=	PREFIX=${PREFIX}

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/parchive
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/parchive

.include "../../mk/bsd.pkg.mk"
