# $NetBSD: Makefile,v 1.17 2008/06/16 15:36:07 joerg Exp $
#

DISTNAME=		dmesg2gif-1.3
PKGREVISION=		2
CATEGORIES=		sysutils
MASTER_SITES=		# empty
DISTFILES=		# empty

MAINTAINER=		pkgsrc-users@NetBSD.org
COMMENT=		Output dmesg(8) device tree as GIF image

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=		graphviz-[0-9]*:../../graphics/graphviz

WRKSRC=			${WRKDIR}
EXTRACT_ONLY=		# empty
NO_BUILD=		yes
NO_CHECKSUM=		yes
NO_CONFIGURE=		yes
USE_TOOLS+=		perl:run
INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_SCRIPT} ${FILESDIR}/dmesg2gif ${DESTDIR}${PREFIX}/bin/dmesg2gif
	${INSTALL_MAN} ${FILESDIR}/dmesg2gif.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/dmesg2gif.1

.include "../../mk/bsd.pkg.mk"
