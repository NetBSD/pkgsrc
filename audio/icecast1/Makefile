# $NetBSD: Makefile,v 1.16 2005/12/05 23:55:02 rillig Exp $
#

DISTNAME=	icecast-1.3.12
PKGREVISION=	6
CATEGORIES=	audio
MASTER_SITES=	http://www.icecast.org/releases/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.icecast.org/
COMMENT=	Internet broadcasting system using Mpeg Layer III streaming

GNU_CONFIGURE=		yes
USE_PKGINSTALL=		yes

RCD_SCRIPTS=		icecast
PKG_SYSCONFSUBDIR=	icecast

CONFIGURE_ARGS+=	--with-readline \
			--with-libwrap \
			--with-python \
			--sysconfdir=${PKG_SYSCONFDIR:Q}
CPPFLAGS+=		-I${BUILDLINK_PREFIX.readline}/include/readline
CPPFLAGS+=		${BUILDLINK_CPPFLAGS.${PYPACKAGE}}
LDFLAGS+=		${BUILDLINK_LDFLAGS.${PYPACKAGE}}
LIBS+=			-lutil
PTHREAD_OPTS+=		require

EGDIR=			${PREFIX}/share/examples/icecast
EGFILES=		groups.aut mounts.aut users.aut icecast.conf

.for f in ${EGFILES}
CONF_FILES+=		${EGDIR}/${f}.dist ${PKG_SYSCONFDIR}/${f}
.endfor

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
