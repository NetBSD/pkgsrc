# $NetBSD: Makefile,v 1.20 2012/12/16 01:51:58 obache Exp $
#

DISTNAME=	herrie-2.2
PKGREVISION=	7
CATEGORIES=	audio
MASTER_SITES=	http://herrie.info/distfiles/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://herrie.info/
COMMENT=	Minimalistic, ncurses-based audio player

HAS_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake msgfmt pkg-config
USE_PKGLOCALEDIR=	yes

CONFIGURE_ARGS+=	verbose

EGDIR=			${PREFIX}/share/examples/herrie
CONF_FILES=		${EGDIR}/herrie.conf ${PKG_SYSCONFDIR}/herrie.conf

CONFIGURE_ENV+=		CONFDIR=${PKG_SYSCONFDIR:Q}
CONFIGURE_ENV+=		MANDIR=${PREFIX}/${PKGMANDIR}
CONFIGURE_ENV+=		TRANSDIR=${PREFIX}/${PKGLOCALEDIR}/locale

RESOLV_AUTO_VARS=	yes
USE_FEATURES=		snprintf regcomp
USE_NCURSES=		yes

AUTO_MKDIRS=		yes

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
