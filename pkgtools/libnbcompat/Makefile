# $NetBSD: Makefile,v 1.1.1.1 2003/03/31 05:02:17 grant Exp $
#

DISTNAME=		libnbcompat-20030331
CATEGORIES=		pkgtools
MASTER_SITES=		# empty
DISTFILES=		# empty

MAINTAINER=		grant@NetBSD.org
HOMEPAGE=		http://www.NetBSD.org/
COMMENT=		Portable NetBSD compatibility library

GNU_CONFIGURE=		# defined

NO_PKGTOOLS_REQD_CHECK=	# defined
NO_CHECKSUM=		# defined
NO_PATCH=		# defined

do-extract:
	@${CP} -Rp ${FILESDIR} ${WRKSRC}

.include "../../mk/bsd.pkg.mk"
