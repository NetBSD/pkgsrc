# $NetBSD: Makefile,v 1.6 2002/12/14 04:34:39 jschauma Exp $
#

DISTNAME=	fastjar-0.93
CATEGORIES=	archivers
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=fastjar/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://fastjar.sourceforge.net/
COMMENT=	C language version of the 'jar' archiver normally used by Java

GNU_CONFIGURE=	YES
USE_BUILDLINK2=	YES

post-install:
	${INSTALL_MAN} ${WRKSRC}/fastjar.1 ${PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/grepjar.1 ${PREFIX}/man/man1

.include "../../devel/zlib/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
