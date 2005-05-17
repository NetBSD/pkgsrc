# $NetBSD: Makefile,v 1.30 2005/05/17 15:08:57 adam Exp $

DISTNAME=	atari800-1.3.6
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=atari800/}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} xf25.zip

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	http://atari800.sourceforge.net/
COMMENT=	Atari 800, 800XL, 130XE and 5200 emulator

RESTRICTED=		"copyrighted ROM images"
NO_SRC_ON_FTP=		${RESTRICTED}
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}
NO_BIN_ON_CDROM=	${RESTRICTED}

WRKSRC=			${WRKDIR}/${DISTNAME}/src
USE_GNU_TOOLS+=		make
GNU_CONFIGURE=		yes

.include "options.mk"

# override HOME to avoid picking up a bad ${HOME}/.atari800 during the build
MAKE_FLAGS+=	HOME=${WRKSRC}

post-extract:
	@cd ${WRKDIR} && ${LOCALBASE}/bin/unzip -Lqo ${DISTDIR}/xf25.zip
	${SED} -e 's,@PREFIX@,${PREFIX},g' <${FILESDIR}/atari800.cfg \
		>${WRKSRC}/atari800.cfg

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/atari800
	${INSTALL_DATA} ${WRKDIR}/*.rom ${WRKDIR}/*.xfd ${WRKDIR}/*.atr \
		${WRKSRC}/atari800.cfg ${PREFIX}/share/atari800/

.include "../../graphics/png/buildlink3.mk"
.include "../../mk/ossaudio.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
