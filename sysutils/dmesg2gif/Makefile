# $NetBSD: Makefile,v 1.5 2003/10/20 12:34:43 hubertf Exp $
#

DISTNAME=		dmesg2gif-1.1
WRKSRC=			${WRKDIR}
CATEGORIES=		sysutils
MASTER_SITES=		# empty
DISTFILES=		# empty

MAINTAINER=		hubertf@NetBSD.org
COMMENT=		Output dmesg(8) device tree as GIF graph

USE_PKGINSTALL=		YES

DEPENDS+=		graphviz-[0-9]*:.../../graphics/graphviz

USE_PERL5=	yes
EXTRACT_ONLY=	# empty
NO_CHECKSUM=	yes
NO_CONFIGURE=	yes
NO_BUILD=	yes

do-install:
	${INSTALL_SCRIPT} ${FILESDIR}/dmesg2gif ${PREFIX}/bin/dmesg2gif

.include "../../mk/bsd.pkg.mk"
