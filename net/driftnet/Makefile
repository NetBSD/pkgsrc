# $NetBSD: Makefile,v 1.33 2020/06/05 12:49:13 jperkin Exp $

DISTNAME=	driftnet-0.1.6
PKGREVISION=	13
CATEGORIES=	net graphics
MASTER_SITES=	http://www.ex-parrot.com/~chris/driftnet/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.ex-parrot.com/~chris/driftnet/
COMMENT=	Real-time image sniffer
LICENSE=	gnu-gpl-v2

DEPENDS+=	mpg123-[0-9]*:../../audio/mpg123

MAKE_JOBS_SAFE=		no

BUILD_TARGET=	default
MAKE_ENV+=	CAT=${CAT:Q} TRUE=${TRUE:Q}
USE_TOOLS+=	makedepend

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/driftnet ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/driftnet.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../graphics/giflib/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../net/libpcap/buildlink3.mk"
.include "../../x11/gtk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
