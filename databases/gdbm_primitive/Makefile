# $NetBSD: Makefile,v 1.9 2004/01/20 12:12:49 agc Exp $
#

DISTNAME=	gdbm-prim-1.15
PKGNAME=	${DISTNAME:S/-prim/_primitive/}
PKGREVISION=	1
CATEGORIES=	databases
MASTER_SITES=	http://homepage.mac.com/leffert/.cv/leffert/Public/
EXTRACT_SUFX=	.tar.gz-link.gz

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://homepage.mac.com/leffert/FileSharing.html
COMMENT=	Shell primitives for working with GDBMs

WRKSRC=			${WRKDIR}/${PKGNAME_NOREV}
EXTRACT_CMD=		${_DFLT_EXTRACT_CMD}
USE_BUILDLINK2=		YES

.include "../../databases/gdbm/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
