# $NetBSD: Makefile,v 1.6 2003/03/29 12:40:25 jmmv Exp $
#

DISTNAME=	gdbm-prim-1.15
PKGNAME=	${DISTNAME:S/-prim/_primitive/}
PKGREVISION=	1
WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}
CATEGORIES=	databases
MASTER_SITES=	http://homepage.mac.com/leffert/.cv/leffert/Public/
EXTRACT_SUFX=	.tar.gz-link.gz

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://homepage.mac.com/leffert/FileSharing.html
COMMENT=	Shell primitives for working with GDBMs

EXTRACT_CMD=		${_DFLT_EXTRACT_CMD}
USE_BUILDLINK2=		YES

.include "../../databases/gdbm/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
