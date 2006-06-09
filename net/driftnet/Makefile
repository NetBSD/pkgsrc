# $NetBSD: Makefile,v 1.20 2006/06/09 06:33:27 joerg Exp $
#

DISTNAME=	driftnet-0.1.6
PKGREVISION=	6
CATEGORIES=	net graphics
MASTER_SITES=	http://www.ex-parrot.com/~chris/driftnet/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.ex-parrot.com/~chris/driftnet/
COMMENT=	Real-time image sniffer

DEPENDS+=	mpg123-[0-9]*:../../audio/mpg123


BUILD_TARGET=	default
MAKE_ENV+=	CAT=${CAT:Q} TRUE=${TRUE:Q}
USE_TOOLS+=	makedepend

INSTALLATION_DIRS=	bin man/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/driftnet ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/driftnet.1 ${PREFIX}/man/man1

.include "../../graphics/libungif/buildlink3.mk"
.include "../../x11/gtk/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
