# $NetBSD: Makefile,v 1.25 2003/09/14 07:36:12 grant Exp $
#

DISTNAME=		libnbcompat-20030914
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

PKG_INFO=		PKG_DBDIR=${_PKG_DBDIR} ${PKG_INFO_CMD}
PKG_CREATE=		PKG_DBDIR=${_PKG_DBDIR} ${PKG_CREATE_CMD}
PKG_DELETE=		PKG_DBDIR=${_PKG_DBDIR} ${PKG_DELETE_CMD}

do-extract:
	@${CP} -Rp ${FILESDIR} ${WRKSRC}

.include "../../mk/bsd.pkg.mk"
