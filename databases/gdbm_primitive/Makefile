# $NetBSD: Makefile,v 1.17 2010/01/29 17:00:26 joerg Exp $
#

DISTNAME=	gdbm-prim-1.15
PKGNAME=	${DISTNAME:S/-prim/_primitive/}
PKGREVISION=	2
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_LOCAL}
EXTRACT_SUFX=	.tar.gz-link.gz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	# http://homepage.mac.com/leffert/FileSharing.html
COMMENT=	Shell primitives for working with GDBMs

PKG_DESTDIR_SUPPORT=	user-destdir

EXTRACT_OPTS=		-f tar
MAKE_ENV+=		BUILDLINK_LDFLAGS=${BUILDLINK_LDFLAGS:Q}
WRKSRC=			${WRKDIR}/${PKGNAME_NOREV}

.include "../../databases/gdbm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
