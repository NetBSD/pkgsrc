# $NetBSD: Makefile,v 1.5 2016/02/26 10:32:47 jperkin Exp $
#

DISTNAME=	CRF++-0.58
CATEGORIES=	textproc
MASTER_SITES=	http://crfpp.googlecode.com/files/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://taku910.github.io/crfpp/
COMMENT=	Yet Another CRF toolkit
LICENSE=	gnu-lgpl-v2.1 OR 2-clause-bsd

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake

PTHREAD_AUTO_VARS=	yes

SUBST_CLASSES+=			pthread_flags
SUBST_STAGE.pthread_flags=	pre-configure
SUBST_FILES.pthread_flags=	configure
SUBST_SED.pthread_flags=	-e 's/-lpthread/'${PTHRAD_LIBS:M*:Q}' '${PTHREAD_LDFLAGS:M*:Q}'/'

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
