# $NetBSD: Makefile,v 1.15 2004/07/03 02:50:32 grant Exp $
#

DISTNAME=		pax-20040703
CATEGORIES=		archivers pkgtools
MASTER_SITES=		# empty
DISTFILES=		# empty

MAINTAINER=		grant@NetBSD.org
HOMEPAGE=		http://www.NetBSD.org/
COMMENT=		POSIX standard archiver with many extensions

USE_BUILDLINK3=		yes
GNU_CONFIGURE=		# defined

NO_PKGTOOLS_REQD_CHECK=	# defined
NO_CHECKSUM=		# defined
NO_MTREE=               # defined
NO_PKG_REGISTER=        # defined
NO_PACKAGE=             Deinstallation is not permitted
PKG_PRESERVE=           # defined

do-extract:
	@${CP} -Rp ${FILESDIR} ${WRKSRC}

.include "../../pkgtools/libnbcompat/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
