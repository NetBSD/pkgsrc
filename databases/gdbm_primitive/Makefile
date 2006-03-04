# $NetBSD: Makefile,v 1.15 2006/03/04 21:29:08 jlam Exp $
#

DISTNAME=	gdbm-prim-1.15
PKGNAME=	${DISTNAME:S/-prim/_primitive/}
PKGREVISION=	2
CATEGORIES=	databases
MASTER_SITES=	http://homepage.mac.com/leffert/.cv/leffert/Public/
EXTRACT_SUFX=	.tar.gz-link.gz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://homepage.mac.com/leffert/FileSharing.html
COMMENT=	Shell primitives for working with GDBMs

EXTRACT_OPTS=		-f tar
MAKE_ENV+=		BUILDLINK_LDFLAGS=${BUILDLINK_LDFLAGS:Q}
WRKSRC=			${WRKDIR}/${PKGNAME_NOREV}

.include "../../databases/gdbm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
