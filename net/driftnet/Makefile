# $NetBSD: Makefile,v 1.3 2003/04/25 20:22:04 jmmv Exp $
#

DISTNAME=	driftnet-0.1.6
CATEGORIES=	graphics net
MASTER_SITES=	http://www.ex-parrot.com/~chris/driftnet/

MAINTAINER=	hubertf@netbsd.org
HOMEPAGE=	http://www.ex-parrot.com/~chris/driftnet/
COMMENT=	Real-time image sniffer

ALL_TARGET=	default
USE_GMAKE=	yes
USE_BUILDLINK2=	yes

do-install:
		${INSTALL_PROGRAM} ${WRKSRC}/driftnet ${PREFIX}/bin
		${INSTALL_MAN} ${WRKSRC}/driftnet.1 ${PREFIX}/man/man1

.include "../../graphics/libungif/buildlink2.mk"
.include "../../x11/gtk/buildlink2.mk"
.include "../../graphics/jpeg/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
