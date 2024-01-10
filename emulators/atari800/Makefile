# $NetBSD: Makefile,v 1.58 2024/01/10 17:57:15 adam Exp $

DISTNAME=		atari800-5.2.0-src
PKGNAME=		${DISTNAME:S/-src//}
CATEGORIES=		emulators
MASTER_SITES=		${MASTER_SITE_GITHUB:=atari800/}
GITHUB_RELEASE=		ATARI800_${PKGVERSION_NOREV:S/./_/g}
EXTRACT_SUFX=		.tgz
DISTFILES+=		${DISTNAME}${EXTRACT_SUFX} pcxf380.zip
SITES.pcxf380.zip=	http://www.emulators.com/freefile/

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	https://atari800.github.io/
COMMENT=	Atari 800, 800XL, 130XE and 5200 emulator
LICENSE=	gnu-gpl-v2

WRKSRC=			${WRKDIR}/${PKGNAME_NOREV}
USE_TOOLS+=		gmake unzip
CONFIGURE_ARGS+=	--disable-sdltest
CONFIGURE_ARGS+=	--with-sound=sdl
CONFIGURE_ARGS+=	--with-video=sdl
CONFIGURE_ARGS.Darwin+=	--disable-rserial
GNU_CONFIGURE=		yes

INSTALLATION_DIRS+=	${PREFIX}/share/atari800

# override HOME to avoid picking up a bad ${HOME}/.atari800 during the build
MAKE_FLAGS+=	HOME=${WRKSRC}

SUBST_CLASSES+=		cfg-path
SUBST_STAGE.cfg-path=	pre-configure
SUBST_MESSAGE.cfg-path=	Setting config path.
SUBST_FILES.cfg-path=	src/cfg.c
SUBST_SED.cfg-path=	-e 's,"/etc,"${PREFIX}/share/atari800,g'

post-extract:
	cd ${WRKDIR} && unzip -Lqo ${DISTDIR}/pcxf380.zip
	sed -e 's,@PREFIX@,${PREFIX},g' ${FILESDIR}/atari800.cfg \
		>${WRKSRC}/atari800.cfg

post-install:
	${INSTALL_DATA} ${WRKDIR}/*.rom ${WRKDIR}/*.xfd ${WRKDIR}/*.atr \
		${WRKSRC}/atari800.cfg ${DESTDIR}${PREFIX}/share/atari800/

.include "../../devel/SDL/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../mk/readline.buildlink3.mk"
.include "../../mk/termcap.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
