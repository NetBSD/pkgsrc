# $NetBSD: Makefile,v 1.30 2022/06/28 11:35:56 wiz Exp $
#

DISTNAME=		dmesg2gif-1.3
PKGREVISION=		13
CATEGORIES=		sysutils
MASTER_SITES=		# empty
DISTFILES=		# empty

MAINTAINER=		pkgsrc-users@NetBSD.org
COMMENT=		Output dmesg(8) device tree as GIF image
LICENSE=		2-clause-bsd

DEPENDS+=		graphviz-[0-9]*:../../graphics/graphviz

WRKSRC=			${WRKDIR}
NO_BUILD=		yes
NO_CONFIGURE=		yes
USE_TOOLS+=		perl:run
INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_SCRIPT} ${FILESDIR}/dmesg2gif ${DESTDIR}${PREFIX}/bin/dmesg2gif
	${INSTALL_MAN} ${FILESDIR}/dmesg2gif.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/dmesg2gif.1

.include "../../mk/bsd.pkg.mk"
