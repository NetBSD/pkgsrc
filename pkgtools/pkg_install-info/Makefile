# $NetBSD: Makefile,v 1.26 2025/07/02 08:26:47 jperkin Exp $
#

PKGNAME=		pkg_install-info-${VERSION}
PKGREVISION=		3
CATEGORIES=		pkgtools

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://www.gnu.org/software/texinfo/texinfo.html
COMMENT=		Standalone GNU info file installation utility
LICENSE=		gnu-gpl-v2 # or later

GNU_CONFIGURE=		yes
FORCE_C_STD=		c99

CFLAGS.SunOS+=		-D__EXTENSIONS__

CHECK_PERMS=		no

# Don't change this unless the sources are updated from GNU Texinfo.
# Otherwise use PKGREVISION if you need to change this package version.
VERSION=		4.5

USE_BSD_MAKEFILE=	yes

INSTALLATION_DIRS=	bin

do-extract:
	@${CP} -R ${FILESDIR} ${WRKSRC}

.include "../../mk/bsd.pkg.mk"
