# $NetBSD: Makefile,v 1.5 2003/07/21 17:14:06 martti Exp $
#

DISTNAME=		mtree-20030630
CATEGORIES=		pkgtools
MASTER_SITES=		# empty
DISTFILES=		# empty

MAINTAINER=		grant@NetBSD.org
HOMEPAGE=		http://www.NetBSD.org/
COMMENT=		Utility for mapping directory hierarchies

USE_BUILDLINK2=		# defined
GNU_CONFIGURE=		# defined

NO_PKGTOOLS_REQD_CHECK=	# defined
NO_CHECKSUM=		# defined
NO_MTREE=               # defined
NO_PKG_REGISTER=        # defined
NO_PACKAGE=             Deinstallation is not permitted
PKG_PRESERVE=           # defined

do-extract:
	@${CP} -Rp ${FILESDIR} ${WRKSRC}

.include "../../pkgtools/libnbcompat/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
