# $NetBSD: Makefile,v 1.15 2006/03/14 14:02:01 joerg Exp $
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

INSTALLATION_DIRS=	man/man1

post-install:
	${INSTALL_MAN} ${WRKSRC}/fastjar.1 ${PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/grepjar.1 ${PREFIX}/man/man1

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
