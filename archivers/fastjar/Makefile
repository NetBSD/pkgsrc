# $NetBSD: Makefile,v 1.4.2.1 2002/05/11 02:08:48 jlam Exp $
#

DISTNAME=	fastjar-0.90
CATEGORIES=	archivers
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=fastjar/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://fastjar.sourceforge.net/
COMMENT=	C language version of the 'jar' archiver normally used by Java

GNU_CONFIGURE=		YES
USE_BUILDLINK2_ONLY=	YES

.include "../../devel/zlib/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
