# $NetBSD: Makefile,v 1.12 1998/04/24 09:20:33 agc Exp $
#

DISTNAME=       timidity-0.2i
CATEGORIES=     audio
MASTER_SITES=   ftp://ftp.cdrom.com/pub/demos/music/samples/ \
		http://www.cgs.fi/~tt/timidity/
TIINS=          dgguspat.zip
DISTFILES=      ${TIINS} ${DISTNAME}.tar.gz

MAINTAINER=     mycroft@NetBSD.ORG

BUILD_DEPENDS=  unzip:../../archivers/unzip
RUN_DEPENDS=	wish8.0:../../x11/tk80
DEPENDS+=	ncurses-1.9.9g:../../devel/ncurses
DEPENDS+=	tk-8.0p2:../../x11/tk80

NO_CDROM=       "Uses copyrighted patches"

EXTRACT_ONLY=   ${DISTNAME}.tar.gz
INSTALL_TARGET= install.all
MAN1=           timidity.1

do-configure:
	@cd ${WRKSRC} && \
	${SED} "s=%PREFIX%=${PREFIX}=" < gravis.cfg > gravis.cfg.new && \
	${MV} gravis.cfg.new gravis.cfg

post-install:
	cd ${PREFIX}/lib/timidity/patch && \
	unzip -o -q -L ${DISTDIR}/${TIINS}

.include "../../mk/bsd.pkg.mk"
