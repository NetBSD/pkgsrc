# $NetBSD: Makefile,v 1.42 2008/06/20 01:09:18 joerg Exp $

DISTNAME=	atari800-2.0.3
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=atari800/}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} xf25.zip

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	http://atari800.sourceforge.net/
COMMENT=	Atari 800, 800XL, 130XE and 5200 emulator

PKG_DESTDIR_SUPPORT=	user-destdir

RESTRICTED=		copyrighted ROM images
NO_BIN_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_SRC_ON_FTP=		${RESTRICTED}

WRKSRC=			${WRKDIR}/${DISTNAME}/src
USE_TOOLS+=		gmake unzip
GNU_CONFIGURE=		yes

INSTALLATION_DIRS+=	${PREFIX}/share/atari800

.include "options.mk"

# override HOME to avoid picking up a bad ${HOME}/.atari800 during the build
MAKE_FLAGS+=	HOME=${WRKSRC:Q}

post-extract:
	cd ${WRKDIR} && unzip -Lqo ${DISTDIR}/xf25.zip
	sed -e 's,@PREFIX@,${PREFIX},g' <${FILESDIR}/atari800.cfg \
		>${WRKSRC}/atari800.cfg

post-install:
	${INSTALL_DATA} ${WRKDIR}/*.rom ${WRKDIR}/*.xfd ${WRKDIR}/*.atr \
		${WRKSRC}/atari800.cfg ${DESTDIR}${PREFIX}/share/atari800/

.include "../../graphics/png/buildlink3.mk"
.include "../../mk/oss.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
