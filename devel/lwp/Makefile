# $NetBSD: Makefile,v 1.2 1999/12/30 09:58:16 fredb Exp $
#

DISTNAME=	lwp-1.0
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.coda.cs.cmu.edu/pub/coda/src/ \
		ftp://ftp.wu-wien.ac.at/pub/systems/coda/src/

MAINTAINER=	fb@enteract.com
HOMEPAGE=	http://www.coda.cs.cmu.edu/

GNU_CONFIGURE=	YES
USE_LIBTOOL=	YES

LTCONFIG_OVERRIDE= ${WRKSRC}/ltconfig

.include "../../mk/bsd.prefs.mk"

# XXX Not yet
#.if defined(LWP_USE_PTH)
#.if ${LWP_USE_PTH} == YES || ${LWP_USE_PTH} == yes
#BUILD_DEPENDS+=	pth:../../devel/pth
#BUILD_DEFS+=		LIBS
#CONFIGURE_ENV+=	LIBS="-lpth -lpthreads"
#.else
pre-configure:
	${CP} ${FILESDIR}/config.cache ${WRKSRC}/
#.endif
#.endif

.include "../../mk/bsd.pkg.mk"
