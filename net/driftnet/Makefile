# $NetBSD: Makefile,v 1.11 2004/10/03 00:17:50 tv Exp $
#

DISTNAME=	driftnet-0.1.6
PKGREVISION=	5
CATEGORIES=	net graphics
MASTER_SITES=	http://www.ex-parrot.com/~chris/driftnet/

MAINTAINER=	hubertf@NetBSD.org
HOMEPAGE=	http://www.ex-parrot.com/~chris/driftnet/
COMMENT=	Real-time image sniffer

DEPENDS=	mpg123-[0-9]*:../../audio/mpg123

USE_BUILDLINK3=	YES

ALL_TARGET=	default
MAKE_ENV+=	CAT="${CAT}" TRUE="${TRUE}"

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/driftnet ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/driftnet.1 ${PREFIX}/man/man1

.include "../../graphics/libungif/buildlink3.mk"
.include "../../x11/gtk/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
