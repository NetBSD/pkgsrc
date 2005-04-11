# $NetBSD: Makefile,v 1.2 2005/04/11 21:47:30 tv Exp $
#

DISTNAME=		xapply-3.4
CATEGORIES=		mine
MASTER_SITES=		http://archive.progeny.com/pundits/
EXTRACT_SUFX=		.tgz

MAINTAINER=		epg@NetBSD.org
COMMENT=		Parallel Execution tool a la xargs/apply

BUILD_DEPENDS+=		mkcmd>=8.14:../../devel/mkcmd


INSTALLATION_DIRS=	bin man/man1
PKG_INSTALLATION_TYPES=	overwrite pkgviews

do-build:
	cd ${WRKSRC}/bin/xapply && \
		MKCMD='-I${LOCALBASE}/lib/mkcmd -I${LOCALBASE}/lib/mkcmd/type' \
		HOSTTYPE= ${SH} ${FILESDIR}/makeme \
		ROOT=${PREFIX} BIN=${PREFIX}/bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/xapply/xapply ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/bin/xapply/xapply.man \
		${PREFIX}/man/man1/xapply.1

.include "../../mk/bsd.pkg.mk"
