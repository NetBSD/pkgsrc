# $NetBSD: Makefile,v 1.29 2012/10/23 17:18:18 asau Exp $
#

DISTNAME=	driftnet-0.1.6
PKGREVISION=	10
CATEGORIES=	net graphics
MASTER_SITES=	http://www.ex-parrot.com/~chris/driftnet/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.ex-parrot.com/~chris/driftnet/
COMMENT=	Real-time image sniffer

DEPENDS+=	mpg123-[0-9]*:../../audio/mpg123

MAKE_JOBS_SAFE=		no

BUILD_TARGET=	default
MAKE_ENV+=	CAT=${CAT:Q} TRUE=${TRUE:Q}
USE_TOOLS+=	makedepend

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/driftnet ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/driftnet.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/giflib.buildlink3.mk"
.include "../../x11/gtk/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
