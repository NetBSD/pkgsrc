# $NetBSD: Makefile,v 1.57 2011/01/19 16:23:02 tron Exp $

DISTNAME=	rpm2pkg-3.2.1
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

INSTALLATION_DIRS=	${PKGMANDIR}/man8 sbin

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../archivers/xz/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/rpm2pkg ${DESTDIR}${PREFIX}/sbin
	${INSTALL_MAN} ${FILESDIR}/rpm2pkg.8 \
	  ${DESTDIR}${PREFIX}/${PKGMANDIR}/man8

.include "../../mk/bsd.pkg.mk"
