# $NetBSD: Makefile,v 1.20 1999/07/06 07:54:59 jlam Exp $
#

DISTNAME=       timidity-0.2i
CATEGORIES=     audio
MASTER_SITES=	${MASTER_SITE_LOCAL}
TIINS=          dgguspat.zip
DISTFILES=      ${TIINS} ${DISTNAME}.tar.gz

MAINTAINER=     mycroft@NetBSD.ORG
HOMEPAGE=	http://www.cgs.fi/~tt/timidity/

BUILD_DEPENDS=  unzip:../../archivers/unzip
DEPENDS+=	ncurses-4.2:../../devel/ncurses
DEPENDS+=	tk-8.0.5:../../x11/tk80

NO_CDROM=       "Uses copyrighted patches"

# this pkg opens some X connectin
IS_INTERACTIVE= yes

EXTRACT_ONLY=   ${DISTNAME}.tar.gz
INSTALL_TARGET= install.all

do-configure:
	@cd ${WRKSRC} && \
	${SED} "s=%PREFIX%=${PREFIX}=" < gravis.cfg > gravis.cfg.new && \
	${MV} gravis.cfg.new gravis.cfg

post-install:
	cd ${PREFIX}/lib/timidity/patch && \
	unzip -o -q -L ${DISTDIR}/${TIINS}

.include "../../mk/bsd.pkg.mk"
