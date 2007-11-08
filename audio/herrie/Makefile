# $NetBSD: Makefile,v 1.2 2007/11/08 04:08:46 bjs Exp $
#

DISTNAME=	herrie-1.8.4
CATEGORIES=	audio
MASTER_SITES=	http://herrie.info/distfiles/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	bjs@NetBSD.org
HOMEPAGE=	http://herrie.info/
COMMENT=	Minimalistic, ncurses-based audio player

PKG_DESTDIR_SUPPORT=	user-destdir

HAS_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake msgfmt pkg-config


CONFIGURE_ARGS+=	no_xspf
CONFIGURE_ARGS+=	verbose

EGDIR=			${PREFIX}/share/examples/herrie
MAKE_ENV+=		MSGFMT=${TOOLS_PATH.msgfmt:Q}
CONFIGURE_ENV+=		CONFDIR=${PKG_SYSCONFDIR:Q}
CONFIGURE_ENV+=		MANDIR=${PREFIX}/${PKGMANDIR}
CONFIGURE_ENV+=		TRANSDIR=${PREFIX}/${PKGLOCALEDIR}/locale

RESOLV_AUTO_VARS=	yes
USE_FEATURES=		snprintf regcomp
USE_NCURSES=		yes

INSTALLATION_DIRS_FROM_PLIST=	yes

.include "options.mk"

SUBST_CLASSES+=		conf
SUBST_STAGE.conf=	pre-configure
SUBST_FILES.conf=	${WRKDIR}/herrie.conf
SUBST_MESSAGE.conf=	Preparing example configuration file.
SUBST_VARS.conf=	DEVOSSAUDIO HERRIE_USE_OSS

post-extract:
	${RUN} ${CP} ${FILESDIR}/herrie.conf ${WRKDIR}

post-install:
	${RUN} ${INSTALL_DATA_DIR} ${DESTDIR}${EGDIR} && \
	${INSTALL_DATA} ${WRKDIR}/herrie.conf ${DESTDIR}${EGDIR}

.include "../../audio/libid3tag/buildlink3.mk"
.include "../../audio/libmad/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/resolv.buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
