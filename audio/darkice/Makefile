# $NetBSD: Makefile,v 1.32 2022/07/02 16:53:04 ryoon Exp $
#

DISTNAME=	darkice-1.4
PKGREVISION=	5
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_GITHUB:=rafael2k/}
GITHUB_RELEASE=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.darkice.org/
COMMENT=	IceCast, IceCast2, and ShoutCast live audio streamer
LICENSE=	gnu-gpl-v3

GNU_CONFIGURE=	yes
# Uses std::regex without setting -std=...
USE_LANGUAGES=	c c++11
USE_TOOLS+=	gmake pkg-config
GCC_REQD+=	4.7 # C++11

EGDIR=		${PREFIX}/share/examples/darkice
HTMLDIR=	${PREFIX}/share/doc/darkice

CONF_FILES=	${EGDIR}/darkice.conf ${PKG_SYSCONFDIR}/darkice.conf

CONFIGURE_ARGS+=	--without-aacplus

.include "../../mk/oss.buildlink3.mk"

.if ${OSS_TYPE} != "none"
LIBS+=			${LIBOSSAUDIO}
SUBST_CLASSES+=		oss
SUBST_STAGE.oss=	pre-configure
SUBST_MESSAGE.oss=	Correcting the path to the OSS device.
SUBST_FILES.oss+=	darkice.cfg
SUBST_FILES.oss+=	man/darkice.cfg.5
SUBST_SED.oss+=		-e "s,/dev/dsp,${DEVOSSAUDIO},g"
.endif

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1 ${PKGMANDIR}/man5

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${EGDIR}
	${INSTALL_DATA_DIR} ${DESTDIR}${HTMLDIR}
	${INSTALL_DATA} ${WRKSRC}/darkice.cfg \
		${DESTDIR}${EGDIR}/darkice.conf
	${INSTALL_PROGRAM} ${WRKSRC}/src/darkice ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/man/darkice.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_MAN} ${WRKSRC}/man/darkice.cfg.5 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man5/darkice.conf.5

.include "options.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
