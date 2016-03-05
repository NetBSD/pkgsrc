# $NetBSD: Makefile,v 1.20 2016/03/05 15:08:30 bsiegert Exp $
#

DISTNAME=	fastjar-0.98
CATEGORIES=	archivers
MASTER_SITES=	http://download.savannah.gnu.org/releases/fastjar/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://savannah.nongnu.org/projects/fastjar
COMMENT=	C language version of the 'jar' archiver normally used by Java
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	YES

INFO_FILES=	YES
INSTALLATION_DIRS=	${PKGMANDIR}/man1

post-install:
	${INSTALL_MAN} ${WRKSRC}/fastjar.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_MAN} ${WRKSRC}/grepjar.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
