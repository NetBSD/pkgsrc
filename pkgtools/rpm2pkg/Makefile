# $NetBSD: Makefile,v 1.56 2011/01/12 00:26:33 tron Exp $

DISTNAME=	rpm2pkg-3.2.0
CATEGORIES=	pkgtools
MASTER_SITES=	# empty
DISTFILES=	# empty
NO_CHECKSUM=	yes

OWNER=		tron@NetBSD.org
HOMEPAGE=	http://www.pkgsrc.org/
COMMENT=	Convert RPM archives to NetBSD packages
LICENSE=	modified-bsd

CONFLICTS+=	suse-base<=6.4

PKG_DESTDIR_SUPPORT=	user-destdir

MANCOMPRESSED_IF_MANZ=	yes
USE_BSD_MAKEFILE=	yes
USE_LANGUAGES=		c99

MAKE_ENV+=	FILESDIR=${FILESDIR:Q}
MAKE_FILE=	${FILESDIR}/Makefile
WRKSRC=		${WRKDIR}

.include "../../mk/compiler.mk"

INSTALLATION_DIRS=	${PKGMANDIR}/man8 ${PKGMANDIR}/cat8 sbin

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../archivers/xz/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
