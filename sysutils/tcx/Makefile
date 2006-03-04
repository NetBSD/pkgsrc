# $NetBSD: Makefile,v 1.6 2006/03/04 21:30:43 jlam Exp $

DISTNAME=	tcx-linux
PKGNAME=	tcx-19940124
CATEGORIES=	sysutils
MASTER_SITES=	ftp://ibiblio.unc.edu/pub/Linux/utils/compress/

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=
COMMENT=	Transparently compress executables

WRKSRC=		${WRKDIR}/tcx

post-patch:
	cd ${WRKSRC}; ${MV} config.h config.h-pre; ${SED} -e 's|@PREFIX@|"${PREFIX}"|g' < config.h-pre > config.h

.include "../../mk/bsd.pkg.mk"
