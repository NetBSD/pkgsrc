# $NetBSD: Makefile,v 1.8 2004/10/03 00:13:06 tv Exp $
#

DISTNAME=	icecast-1.3.12
PKGREVISION=	4
CATEGORIES=	audio
MASTER_SITES=	http://www.icecast.org/releases/

MAINTAINER=	kim@tac.nyc.ny.us
HOMEPAGE=	http://www.icecast.org/
COMMENT=	Internet broadcasting system using Mpeg Layer III streaming

USE_BUILDLINK3=		yes
GNU_CONFIGURE=		# defined
USE_PKGINSTALL=		yes

RCD_SCRIPTS=		icecast
PKG_SYSCONFSUBDIR=	icecast

CONFIGURE_ARGS+=	--with-readline \
			--with-libwrap \
			--with-python \
			--sysconfdir=${PKG_SYSCONFDIR}
CPPFLAGS+=		-I${BUILDLINK_PREFIX.readline}/include/readline
CPPFLAGS+=		${BUILDLINK_CPPFLAGS.${PYPACKAGE}}
CFLAGS+=		${PTHREAD_CFLAGS}
LDFLAGS+=		${PTHREAD_LDFLAGS}
LDFLAGS+=		${BUILDLINK_LDFLAGS.${PYPACKAGE}}
LIBS+=			-lutil
PTHREAD_OPTS+=		require

EGDIR=			${PREFIX}/share/examples/icecast
EGFILES=		groups.aut mounts.aut users.aut icecast.conf

.for f in ${EGFILES}
CONF_FILES+=		${EGDIR}/${f}.dist ${PKG_SYSCONFDIR}/${f}
.endfor
.undef f

.include "../../mk/bsd.prefs.mk"

ICECAST_SOURCE_BUFFSIZE?=	8192
ICECAST_CHUNKLEN?=		64

BUILD_DEFS+=			ICECAST_SOURCE_BUFFSIZE
BUILD_DEFS+=			ICECAST_CHUNKLEN

pre-configure:
	@${MV} ${WRKSRC}/src/icetypes.h ${WRKSRC}/src/icetypes.h.bak
	@${SED} \
		-e 's/@SOURCE_BUFFSIZE@/${ICECAST_SOURCE_BUFFSIZE}/' \
		-e 's/@CHUNKLEN@/${ICECAST_CHUNKLEN}/' \
		${WRKSRC}/src/icetypes.h.bak > ${WRKSRC}/src/icetypes.h

.include "../../devel/readline/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../security/tcp_wrappers/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
