# $NetBSD: Makefile,v 1.16 1998/08/20 15:16:40 tsarna Exp $
#

DISTNAME=       timidity-0.2i
CATEGORIES=     audio
MASTER_SITES=   ftp://ftp.cdrom.com/pub/demos/music/samples/ \
		http://www.cgs.fi/~tt/timidity/
TIINS=          dgguspat.zip
DISTFILES=      ${TIINS} ${DISTNAME}.tar.gz

MAINTAINER=     mycroft@NetBSD.ORG
HOMEPAGE=	http://www.cgs.fi/~tt/timidity/

BUILD_DEPENDS=  unzip:../../archivers/unzip
RUN_DEPENDS=	wish8.0:../../x11/tk80
DEPENDS+=	ncurses-1.9.9g:../../devel/ncurses
DEPENDS+=	tk-8.0p2:../../x11/tk80

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
