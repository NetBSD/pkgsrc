# $NetBSD: Makefile,v 1.7 2003/07/13 13:52:49 wiz Exp $
#

DISTNAME=	driftnet-0.1.6
PKGREVISION=	3
CATEGORIES=	net graphics
MASTER_SITES=	http://www.ex-parrot.com/~chris/driftnet/

MAINTAINER=	hubertf@netbsd.org
HOMEPAGE=	http://www.ex-parrot.com/~chris/driftnet/
COMMENT=	Real-time image sniffer

DEPENDS=	mpg123-[0-9]*:../../audio/mpg123

USE_BUILDLINK2=	YES

ALL_TARGET=	default
MAKE_ENV+=	CAT="${CAT}" TRUE="${TRUE}"

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/driftnet ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/driftnet.1 ${PREFIX}/man/man1

.include "../../graphics/libungif/buildlink2.mk"
.include "../../x11/gtk/buildlink2.mk"
.include "../../graphics/jpeg/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
