# $NetBSD: Makefile,v 1.9 2002/10/09 11:41:31 jlam Exp $
#

DISTNAME=	icecast-1.3.12
CATEGORIES=	audio
MASTER_SITES=	http://www.icecast.org/releases/

MAINTAINER=	hubertf@netbsd.org
HOMEPAGE=	http://www.icecast.org/
COMMENT=	Internet broadcasting system using Mpeg Layer III streaming

USE_BUILDLINK2=		# defined
GNU_CONFIGURE=		# defined
CONFIGURE_ARGS+=	--with-readline \
			--with-libwrap \
			--with-python
CPPFLAGS+=		-I${BUILDLINK_PREFIX.readline}/include/readline
CPPFLAGS+=		${BUILDLINK_CPPFLAGS.${PYPACKAGE}}
LDFLAGS+=		${BUILDLINK_LDFLAGS.${PYPACKAGE}}
LIBS+=			-lutil
PTHREAD_OPTS+=		native

.include "../../devel/readline/buildlink2.mk"
.include "../../lang/python/application.mk"
.include "../../security/tcp_wrappers/buildlink2.mk"
.include "../../mk/pthread.buildlink2.mk"

.if defined(PTHREAD_TYPE) && (${PTHREAD_TYPE} == "none")
.  include "../../devel/unproven-pthreads/buildlink2.mk"
.endif

.include "../../mk/bsd.pkg.mk"
