# $NetBSD: Makefile,v 1.5 2014/01/27 18:41:11 wiz Exp $

DISTNAME=	delta-2006.08.03
PKGREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	http://www.tigris.org/files/documents/3103/33566/

MAINTAINER=	morr@NetBSD.org
HOMEPAGE=	http://delta.tigris.org/
COMMENT=	Heuristically minimizes interesting files
LICENSE=	2-clause-bsd

USE_TOOLS+=	gmake perl
REPLACE_PERL=	delta multidelta
INSTALLATION_DIRS= bin

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/delta ${DESTDIR}${PREFIX}/bin/delta
	${INSTALL_SCRIPT} ${WRKSRC}/multidelta ${DESTDIR}${PREFIX}/bin/multidelta
	${INSTALL_PROGRAM} ${WRKSRC}/topformflat ${DESTDIR}${PREFIX}/bin/topformflat

.include "../../mk/bsd.pkg.mk"
