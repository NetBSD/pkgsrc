# $NetBSD: Makefile,v 1.24 2000/07/28 21:47:49 jlam Exp $
#

DISTNAME=       timidity-0.2i
CATEGORIES=     audio
MASTER_SITES=	${MASTER_SITE_LOCAL}
TIINS=          dgguspat.zip
DISTFILES=      ${TIINS} ${DISTNAME}.tar.gz

MAINTAINER=     mycroft@NetBSD.ORG
HOMEPAGE=	http://www.cgs.fi/~tt/timidity/

BUILD_DEPENDS=  unzip:../../archivers/unzip
DEPENDS+=	tk-8.0.5:../../x11/tk80

USE_CURSES=	# defined

NO_CDROM=       "Uses copyrighted patches"

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

.if defined(NEED_NCURSES) && ${NEED_NCURSES} == "YES"
EXTRAINCS+=	-DHAVE_NCURSES_H=1 -I${LOCALBASE}/include
EXTRALIBS+=	-Wl,-R${LOCALBASE}/lib -L${LOCALBASE}/lib -lncurses
MAKE_ENV+=	EXTRAINCS="${EXTRAINCS}"
.else
EXTRALIBS+=	-lcurses -ltermcap
.endif

MAKE_ENV+=	EXTRALIBS="${EXTRALIBS}"
