# $NetBSD: Makefile,v 1.20 2012/09/11 23:19:37 asau Exp $
#

DISTNAME=		pkg_install-info-${VERSION}
PKGREVISION=		3
CATEGORIES=		pkgtools
MASTER_SITES=		# empty
DISTFILES=		# empty

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.gnu.org/software/texinfo/texinfo.html
COMMENT=		Standalone GNU info file installation utility

PKG_INSTALLATION_TYPES=	overwrite pkgviews

GNU_CONFIGURE=		yes

CHECK_PERMS=		no

# Don't change this unless the sources are updated from GNU Texinfo.
# Otherwise use PKGREVISION if you need to change this package version.
VERSION=		4.5

USE_BSD_MAKEFILE=	yes

INSTALLATION_DIRS=	bin

do-extract:
	@${CP} -R ${FILESDIR} ${WRKSRC}

.include "../../mk/bsd.pkg.mk"
