# $NetBSD: Makefile,v 1.12 2003/09/30 10:30:33 xtraeme Exp $
#

DISTNAME=	icecast-1.3.12
PKGREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	http://www.icecast.org/releases/

MAINTAINER=	hubertf@NetBSD.org
HOMEPAGE=	http://www.icecast.org/
COMMENT=	Internet broadcasting system using Mpeg Layer III streaming

USE_BUILDLINK2=		# defined
GNU_CONFIGURE=		# defined
USE_PKGINSTALL=		yes

RCD_SCRIPTS=		icecast
PKG_SYSCONFSUBDIR=	icecast

CONFIGURE_ARGS+=	--with-readline \
			--with-libwrap \
			--with-python
CPPFLAGS+=		-I${BUILDLINK_PREFIX.readline}/include/readline
CPPFLAGS+=		${BUILDLINK_CPPFLAGS.${PYPACKAGE}}
CFLAGS+=		${PTHREAD_CFLAGS}
LDFLAGS+=		${PTHREAD_LDFLAGS}
LDFLAGS+=		${BUILDLINK_LDFLAGS.${PYPACKAGE}}
LIBS+=			-lutil
PTHREAD_OPTS+=		native

EGDIR=			${PREFIX}/share/examples/icecast
FILES=			groups.aut mounts.aut users.aut icecast.conf

.for F in ${FILES}
CONF_FILES+=		${EGDIR}/${F}.dist ${PKG_SYSCONFDIR}/${F}
.endfor
			
.include "../../devel/readline/buildlink2.mk"
.include "../../lang/python/application.mk"
.include "../../security/tcp_wrappers/buildlink2.mk"
.include "../../mk/pthread.buildlink2.mk"

.if defined(PTHREAD_TYPE) && (${PTHREAD_TYPE} == "none")
.  include "../../devel/unproven-pthreads/buildlink2.mk"
.endif

.include "../../mk/bsd.pkg.mk"
