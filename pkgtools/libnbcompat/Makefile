# $NetBSD: Makefile,v 1.15 2003/09/03 07:07:04 jlam Exp $
#

DISTNAME=		libnbcompat-20030825
CATEGORIES=		pkgtools
MASTER_SITES=		# empty
DISTFILES=		# empty

MAINTAINER=		grant@NetBSD.org
HOMEPAGE=		http://www.NetBSD.org/
COMMENT=		Portable NetBSD compatibility library

NO_TOOLS=		# defined
NO_BUILDLINK=		# defined
NO_PKGTOOLS_REQD_CHECK=	# defined
NO_CHECKSUM=		# defined
NO_MTREE=		# defined

GNU_CONFIGURE=		# defined

PKG_INFO=		PKG_DBDIR=${PKG_DBDIR} ${PKG_INFO_CMD}
PKG_CREATE=		PKG_DBDIR=${PKG_DBDIR} ${PKG_CREATE_CMD}

do-extract:
	@${CP} -Rp ${FILESDIR} ${WRKSRC}

.include "../../mk/bsd.pkg.mk"
