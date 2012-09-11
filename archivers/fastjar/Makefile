# $NetBSD: Makefile,v 1.18 2012/09/11 19:46:53 asau Exp $
#

DISTNAME=	fastjar-0.93
PKGREVISION=	3
CATEGORIES=	archivers
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=fastjar/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://fastjar.sourceforge.net/
COMMENT=	C language version of the 'jar' archiver normally used by Java

PKG_INSTALLATION_TYPES=	overwrite pkgviews

GNU_CONFIGURE=	YES

INSTALLATION_DIRS=	${PKGMANDIR}/man1

post-install:
	${INSTALL_MAN} ${WRKSRC}/fastjar.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_MAN} ${WRKSRC}/grepjar.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
