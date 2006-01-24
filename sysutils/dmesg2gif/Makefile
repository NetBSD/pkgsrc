# $NetBSD: Makefile,v 1.12 2006/01/24 07:32:34 wiz Exp $
#

DISTNAME=		dmesg2gif-1.3
PKGREVISION=		1
CATEGORIES=		sysutils
MASTER_SITES=		# empty
DISTFILES=		# empty

MAINTAINER=		hubertf@NetBSD.org
COMMENT=		Output dmesg(8) device tree as GIF image

DEPENDS+=		graphviz-[0-9]*:../../graphics/graphviz

WRKSRC=			${WRKDIR}
EXTRACT_ONLY=		# empty
NO_BUILD=		yes
NO_CHECKSUM=		yes
NO_CONFIGURE=		yes
USE_TOOLS+=		perl:run
INSTALLATION_DIRS=	bin man/man1

do-install:
	${INSTALL_SCRIPT} ${FILESDIR}/dmesg2gif ${PREFIX}/bin/dmesg2gif
	${INSTALL_MAN} ${FILESDIR}/dmesg2gif.1 ${PREFIX}/man/man1/dmesg2gif.1

.include "../../mk/bsd.pkg.mk"
