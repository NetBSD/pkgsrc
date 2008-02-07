# $NetBSD: Makefile,v 1.7 2008/02/07 12:41:19 obache Exp $
#

.include "../../databases/qdbm/Makefile.common"

PKGNAME=	${RUBY_PKGPREFIX}-qdbm-1.0.0.${QDBM_VERSION}
CATEGORIES=	databases ruby

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://qdbm.sourceforge.net/
COMMENT=	Ruby interface of QDBM

PKG_DESTDIR_SUPPORT=	user-destdir

MY_SUBDIR=ruby
BUILD_DIRS=	${MY_SUBDIR}
CONFIGURE_DIRS=	${MY_SUBDIR}

GNU_CONFIGURE=		yes
TEST_TARGET=		check
#USE_RUBY_EXTCONF=	yes
#RUBY_EXTCONF_SUBDIRS=	${MY_SUBDIR}/curia ${MY_SUBDIR}/depot ${MY_SUBDIR}/villa
RUBY_HAS_ARCHLIB=	yes

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
