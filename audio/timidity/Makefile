# $NetBSD: Makefile,v 1.27 2000/11/02 03:25:32 wiz Exp $
#

DISTNAME=       timidity-0.2i
CATEGORIES=     audio
MASTER_SITES=	${MASTER_SITE_LOCAL}
TIINS=          dgguspat.zip
DISTFILES=      ${TIINS} ${DISTNAME}.tar.gz

MAINTAINER=     mycroft@NetBSD.ORG
HOMEPAGE=	http://www.cgs.fi/~tt/timidity/

BUILD_DEPENDS=  unzip:../../archivers/unzip
DEPENDS+=	tk-8.3.2:../../x11/tk

USE_CURSES=	# defined

RESTRICTED=		"Uses copyrighted patches"
NO_BIN_ON_FTP=		${RESTRICTED}
NO_BIN_ON_CDROM=	${RESTRICTED}

EXTRACT_ONLY=   ${DISTNAME}.tar.gz
INSTALL_TARGET= install.all

do-configure:
	@cd ${WRKSRC} && \
	${SED} "s=%PREFIX%=${PREFIX}=" < gravis.cfg > gravis.cfg.new && \
	${MV} gravis.cfg.new gravis.cfg

post-install:
	cd ${PREFIX}/share/timidity/patch && \
	unzip -o -q -L ${DISTDIR}/${TIINS}

.include "../../mk/bsd.prefs.mk"

.if defined(NEED_NCURSES) && ${NEED_NCURSES} == "YES"
EXTRAINCS+=	-DHAVE_NCURSES_H=1 -I${LOCALBASE}/include
EXTRALIBS+=	-Wl,-R${LOCALBASE}/lib -L${LOCALBASE}/lib -lncurses
MAKE_ENV+=	EXTRAINCS="${EXTRAINCS}"
.else
EXTRALIBS+=	-lcurses -ltermcap
.endif

MAKE_ENV+=	EXTRALIBS="${EXTRALIBS}"

.include "../../mk/bsd.pkg.mk"
