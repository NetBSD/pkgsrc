# $NetBSD: Makefile,v 1.11 2023/06/06 12:42:24 riastradh Exp $
#

DISTNAME=		xapply-3.4
PKGREVISION=		1
CATEGORIES=		sysutils
MASTER_SITES=		http://archive.progeny.com/pundits/
EXTRACT_SUFX=		.tgz

MAINTAINER=		pkgsrc-users@NetBSD.org
COMMENT=		Parallel Execution tool a la xargs/apply

TOOL_DEPENDS+=		mkcmd>=8.14:../../devel/mkcmd

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

USE_TOOLS+=		m4

do-build:
	cd ${WRKSRC}/bin/xapply && \
		MKCMD='-I${LOCALBASE}/lib/mkcmd -I${LOCALBASE}/lib/mkcmd/type' \
		HOSTTYPE= ${SH} ${FILESDIR}/makeme \
		ROOT=${PREFIX} BIN=${PREFIX}/bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/xapply/xapply ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/bin/xapply/xapply.man \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/xapply.1

.include "../../mk/bsd.pkg.mk"
