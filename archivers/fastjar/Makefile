# $NetBSD: Makefile,v 1.9 2004/03/11 18:03:49 xtraeme Exp $
#

DISTNAME=	fastjar-0.93
CATEGORIES=	archivers
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=fastjar/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://fastjar.sourceforge.net/
COMMENT=	C language version of the 'jar' archiver normally used by Java

GNU_CONFIGURE=	YES
USE_BUILDLINK3=	YES

post-install:
	${INSTALL_MAN} ${WRKSRC}/fastjar.1 ${PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/grepjar.1 ${PREFIX}/man/man1

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
