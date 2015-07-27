# $NetBSD: Makefile,v 1.7 2015/07/27 16:32:55 wiz Exp $
#

DISTNAME=		shc-3.8.9
CATEGORIES=		sysutils
MASTER_SITES=		http://www.datsi.fi.upm.es/~frosal/sources/
EXTRACT_SUFX=		.tgz

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.datsi.fi.upm.es/~frosal/
COMMENT=		Shell script to C compiler
LICENSE=        	gnu-gpl-v2

MAKE_FILE=		makefile
MAKE_FLAGS+=		CFLAGS=${CFLAGS:Q}

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/shc ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/shc.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
