# $NetBSD: Makefile,v 1.4.2.2 2002/06/21 23:04:40 jlam Exp $
#

DISTNAME=	fastjar-0.90
CATEGORIES=	archivers
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=fastjar/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://fastjar.sourceforge.net/
COMMENT=	C language version of the 'jar' archiver normally used by Java

GNU_CONFIGURE=	YES
USE_BUILDLINK2=	YES

.include "../../devel/zlib/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
