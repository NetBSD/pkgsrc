# $NetBSD: Makefile,v 1.29 2012/09/12 00:24:39 asau Exp $
#

DISTNAME=	icecast-1.3.12
PKGREVISION=	12
CATEGORIES=	audio
MASTER_SITES=	http://downloads.xiph.org/releases/icecast/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.icecast.org/
COMMENT=	Internet broadcasting system using Mpeg Layer III streaming

RCD_SCRIPTS=		icecast
PKG_SYSCONFSUBDIR=	icecast

GNU_CONFIGURE=		yes
CONFIGURE_ENV+=		VARBASE=${VARBASE}
CONFIGURE_ARGS+=	--with-readline \
			--with-libwrap \
			--with-python \
			--sysconfdir=${PKG_SYSCONFDIR:Q}
CPPFLAGS+=		-I${BUILDLINK_PREFIX.readline}/include/readline
CPPFLAGS+=		${BUILDLINK_CPPFLAGS.${PYPACKAGE}}
LDFLAGS+=		${BUILDLINK_LDFLAGS.${PYPACKAGE}}
PTHREAD_OPTS+=		require

EGDIR=			${PREFIX}/share/examples/icecast
EGFILES=		groups.aut mounts.aut users.aut icecast.conf

.for f in ${EGFILES}
CONF_FILES+=		${EGDIR}/${f}.dist ${PKG_SYSCONFDIR}/${f}
.endfor

.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} != "SunOS"
LIBS+=			-lutil
.endif

ICECAST_SOURCE_BUFFSIZE?=	8192
ICECAST_CHUNKLEN?=		64

BUILD_DEFS+=			ICECAST_SOURCE_BUFFSIZE
BUILD_DEFS+=			ICECAST_CHUNKLEN

SUBST_CLASSES+=		ice
SUBST_STAGE.ice=	pre-configure
SUBST_MESSAGE.ice=	Configuring in src/icetypes.h
SUBST_FILES.ice=	src/icetypes.h
SUBST_SED.ice=		-e 's/@SOURCE_BUFFSIZE@/${ICECAST_SOURCE_BUFFSIZE}/'
SUBST_SED.ice+=		-e 's/@CHUNKLEN@/${ICECAST_CHUNKLEN}/'

.include "../../devel/readline/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../security/tcp_wrappers/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
