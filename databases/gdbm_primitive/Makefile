# $NetBSD: Makefile,v 1.1.1.1 2002/07/04 20:03:29 wiz Exp $
#

DISTNAME=	gdbm-prim-1.15
PKGNAME=	${DISTNAME:S/-prim/_primitive/}
CATEGORIES=	databases
MASTER_SITES=	http://homepage.mac.com/leffert/.cv/leffert/Public/
EXTRACT_SUFX=	.tar.gz-link.gz

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://homepage.mac.com/leffert/FileSharing.html
COMMENT=	Shell primitives for working with GDBMs

EXTRACT_CMD=		${_DFLT_EXTRACT_CMD}
USE_BUILDLINK_ONLY=	YES
WRKSRC=			${WRKDIR}/${PKGNAME}

.include "../../databases/gdbm/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
