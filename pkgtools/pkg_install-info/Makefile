# $NetBSD: Makefile,v 1.1.1.1 2003/06/09 22:16:10 seb Exp $
#

DISTNAME=		pkg_install-info-${VERSION}
CATEGORIES=		pkgtools
MASTER_SITES=		# empty
DISTFILES=		# empty

MAINTAINER=		seb@netbsd.org
HOMEPAGE=		http://www.gnu.org/software/texinfo/texinfo.html
COMMENT=		standalone GNU info file installation utility

USE_BUILDLINK2=		# defined
GNU_CONFIGURE=		# defined

NO_CHECKSUM=		# defined

# Don't change this unless the sources are updated from GNU Texinfo.
# Otherwise use PKGREVISION if you need to change this package version.
VERSION=		4.5

do-extract:
	@${CP} -Rp ${FILESDIR} ${WRKSRC}

.include "../../mk/bsd.pkg.mk"
