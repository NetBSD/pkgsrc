# $NetBSD: Makefile,v 1.3 2003/10/20 03:40:01 grant Exp $
#

DISTNAME=		dmesg2gif-1.0
WRKSRC=			${WRKDIR}
CATEGORIES=		sysutils
MASTER_SITES=		# empty
DISTFILES=		# empty

MAINTAINER=		hubertf@NetBSD.org
COMMENT=		Output dmesg(8) device tree as GIF graph

DEPENDS+=		graphviz-[0-9]*:../../graphics/graphviz

USE_PKGINSTALL=		YES

ONLY_FOR_PLATFORM=	NetBSD-*-*

EXTRACT_ONLY=	# empty
NO_CHECKSUM=	yes
NO_CONFIGURE=	yes
NO_BUILD=	yes

USE_PERL5=	run

do-install:
	${INSTALL_SCRIPT} ${FILESDIR}/dmesg2gif ${PREFIX}/bin/dmesg2gif

.include "../../mk/bsd.pkg.mk"
