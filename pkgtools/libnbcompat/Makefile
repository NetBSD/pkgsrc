# $NetBSD: Makefile,v 1.38 2004/08/13 04:38:02 jlam Exp $
#
# NOTE: If you update this package, it is *mandatory* that you update
# 	pkgsrc/pkgtools/libnbcompat/files/README to reflect the actual
#	list of tested and supported platforms.
#

DISTNAME=		libnbcompat-20040813
CATEGORIES=		pkgtools
MASTER_SITES=		# empty
DISTFILES=		# empty

MAINTAINER=		grant@NetBSD.org
HOMEPAGE=		http://www.NetBSD.org/
COMMENT=		portable NetBSD compatibility library

NO_BUILDLINK=		yes
NO_PKGTOOLS_REQD_CHECK=	yes
NO_CHECKSUM=		yes
NO_MTREE=		yes

GNU_CONFIGURE=		yes

PKG_INFO=		PKG_DBDIR=${_PKG_DBDIR} ${PKG_INFO_CMD}
PKG_CREATE=		PKG_DBDIR=${_PKG_DBDIR} ${PKG_CREATE_CMD}
PKG_DELETE=		PKG_DBDIR=${_PKG_DBDIR} ${PKG_DELETE_CMD}

do-extract:
	@${CP} -Rp ${FILESDIR} ${WRKSRC}

.include "../../mk/bsd.pkg.mk"
