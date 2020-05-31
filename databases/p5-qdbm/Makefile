# $NetBSD: Makefile,v 1.24 2020/05/31 16:38:48 rillig Exp $
#

PKGREVISION= 5
.include "../../databases/qdbm/Makefile.common"

PKGNAME=	p5-qdbm-1.0.0.${QDBM_VERSION}
CATEGORIES=	databases perl5

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://fallabs.com/qdbm/plspex.html
COMMENT=	Perl interface of QDBM
LICENSE=	gnu-lgpl-v2.1

MAKE_JOBS_SAFE=		no

MY_SUBDIR=	perl
BUILD_DIRS=	${MY_SUBDIR}
CONFIGURE_DIRS=	${MY_SUBDIR}

GNU_CONFIGURE=		yes
USE_TOOLS+=		perl
PERL5_CONFIGURE=	no
TEST_TARGET=		check
GNU_CONFIGURE_PTHREAD=	no

PERL5_PACKLIST=	auto/Curia/.packlist auto/Depot/.packlist auto/Villa/.packlist
REPLACE_PERL=	${MY_SUBDIR}/curia/plcrtest ${MY_SUBDIR}/depot/pldptest \
		${MY_SUBDIR}/villa/plvltest

.include "../../databases/qdbm/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.if defined(PTHREAD_TYPE) && ${PTHREAD_TYPE} != "none"
SUBST_CLASSES+=		pthread
SUBST_STAGE.pthread=	pre-configure
SUBST_FILES.pthread=	${MY_SUBDIR}/configure
SUBST_SED.pthread=	-e 's|-lpthread|${PTHREAD_LIBS}|'
.endif
.include "../../mk/bsd.pkg.mk"
