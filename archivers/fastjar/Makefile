# $NetBSD: Makefile,v 1.12 2005/01/30 23:18:38 jmmv Exp $
#

DISTNAME=	fastjar-0.93
PKGREVISION=	2
CATEGORIES=	archivers
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=fastjar/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://fastjar.sourceforge.net/
COMMENT=	C language version of the 'jar' archiver normally used by Java

PKG_INSTALLATION_TYPES=	overwrite pkgviews

GNU_CONFIGURE=	YES
USE_BUILDLINK3=	YES

INSTALLATION_DIRS=	man/man1

post-install:
	${INSTALL_MAN} ${WRKSRC}/fastjar.1 ${PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/grepjar.1 ${PREFIX}/man/man1

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
