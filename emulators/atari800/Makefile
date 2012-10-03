# $NetBSD: Makefile,v 1.48 2012/10/03 12:55:10 asau Exp $

DISTNAME=	atari800-2.2.1
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=atari800/}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} xf25.zip

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	http://atari800.sourceforge.net/
COMMENT=	Atari 800, 800XL, 130XE and 5200 emulator
LICENSE=	gnu-gpl-v2

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
MAKE_FLAGS+=	HOME=${WRKSRC}

post-extract:
	cd ${WRKDIR} && unzip -Lqo ${DISTDIR}/xf25.zip
	sed -e 's,@PREFIX@,${PREFIX},g' <${FILESDIR}/atari800.cfg \
		>${WRKSRC}/atari800.cfg

post-install:
	${INSTALL_DATA} ${WRKDIR}/*.rom ${WRKDIR}/*.xfd ${WRKDIR}/*.atr \
		${WRKSRC}/atari800.cfg ${DESTDIR}${PREFIX}/share/atari800/

.include "../../devel/readline/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../mk/oss.buildlink3.mk"
.include "../../mk/termcap.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
