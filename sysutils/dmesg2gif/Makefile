# $NetBSD: Makefile,v 1.1.1.1 2003/10/20 00:31:29 hubertf Exp $
#

DISTNAME=		dmesg2gif-1.0
WRKSRC=			${WRKDIR}
CATEGORIES=		sysutils
MASTER_SITES=		# empty
DISTFILES=		# empty

MAINTAINER=		hubertf@NetBSD.org
COMMENT=		Output dmesg(8) device tree as GIF graph

USE_PKGINSTALL=		YES

DEPENDS+=		graphviz-[0-9]*:.../../graphics/graphviz

EXTRACT_ONLY=	# empty
NO_CHECKSUM=	yes
NO_CONFIGURE=	yes
NO_BUILD=	yes

do-install:
	${INSTALL_SCRIPT} ${FILESDIR}/dmesg2gif ${PREFIX}/bin/dmesg2gif

.include "../../mk/bsd.pkg.mk"
