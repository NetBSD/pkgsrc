# $NetBSD: Makefile,v 1.13 2012/10/02 21:25:52 asau Exp $
#

.include "../../databases/qdbm/Makefile.common"

PKGNAME=	${RUBY_PKGPREFIX}-qdbm-1.0.0.${QDBM_VERSION}
PKGREVISION=	2
CATEGORIES=	databases ruby

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://qdbm.sourceforge.net/
COMMENT=	Ruby interface of QDBM
LICENSE=	gnu-lgpl-v2.1

MAKE_JOBS_SAFE=	no

MY_SUBDIR=	ruby
BUILD_DIRS=	${MY_SUBDIR}
CONFIGURE_DIRS=	${MY_SUBDIR}

GNU_CONFIGURE=		yes
MAKE_ENV+=		RUBY_EXTCONF_ARGS=${RUBY_EXTCONF_ARGS:Q}
TEST_TARGET=		check
#USE_RUBY_EXTCONF=	yes
#RUBY_EXTCONF_SUBDIRS=	${MY_SUBDIR}/curia ${MY_SUBDIR}/depot ${MY_SUBDIR}/villa
RUBY_EXTCONF_ARGS=	--with-opt-dir=${PREFIX:Q} --vendor
USE_TOOLS+=		gmake

REPLACE_RUBY=	${MY_SUBDIR}/curia/rbcrtest ${MY_SUBDIR}/depot/rbdptest \
		${MY_SUBDIR}/villa/rbvltest

.include "../../databases/qdbm/buildlink3.mk"
.include "../../lang/ruby/modules.mk"
.if defined(PTHREAD_TYPE) && ${PTHREAD_TYPE} != "none"
SUBST_CLASSES+=		pthread
SUBST_STAGE.pthread=	pre-configure
SUBST_FILES.pthread=	${MY_SUBDIR}/configure
SUBST_SED.pthread=	-e 's|-lpthread|${PTHREAD_LIBS}|'
.endif
.include "../../mk/bsd.pkg.mk"
