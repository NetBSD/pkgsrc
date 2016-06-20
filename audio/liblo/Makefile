# $NetBSD: Makefile,v 1.1 2016/06/20 08:09:40 kamil Exp $
#

DISTNAME=	liblo-0.28
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=liblo/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://liblo.sourceforge.net/
COMMENT=	Lightweight Open Sound Control implementation
LICENSE=	gnu-lgpl-v2.1

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_TOOLS+=		pkg-config
USE_LANGUAGES=		c c++

CFLAGS+=		${PTHREAD_CFLAGS}
PKGCONFIG_OVERRIDE+=	liblo.pc.in
PTHREAD_OPTS+=		require
RESOLV_AUTO_VARS=	yes	# gethostbyname and friends

SUBST_CLASSES+=		conf
SUBST_FILES.conf=	configure Makefile.in src/Makefile.in liblo.pc.in
SUBST_MESSAGE.conf=	Performing build-time configuration substitutions.
SUBST_SED.conf=		-e 's,-lpthread,$${PTHREAD_LDFLAGS} $${PTHREAD_LIBS},'
SUBST_STAGE.conf=	post-patch
SUBST_VARS.conf=	PTHREAD_CFLAGS PTHREAD_LDFLAGS PTHREAD_LIBS


.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/resolv.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
