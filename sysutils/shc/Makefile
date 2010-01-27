# $NetBSD: Makefile,v 1.5 2010/01/27 20:01:36 joerg Exp $
#

DISTNAME=		shc-3.7
CATEGORIES=		sysutils
MASTER_SITES=		http://www.datsi.fi.upm.es/~frosal/sources/
EXTRACT_SUFX=		.tgz

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.datsi.fi.upm.es/~frosal/
COMMENT=		Shell script to C compiler

PKG_DESTDIR_SUPPORT=	user-destdir

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/shc ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/shc.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
