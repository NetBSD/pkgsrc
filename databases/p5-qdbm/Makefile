# $NetBSD: Makefile,v 1.1.1.1 2005/11/23 06:36:56 minskim Exp $
#

.include "../../databases/qdbm/Makefile.common"

PKGNAME=	p5-qdbm-1.0.0.${QDBM_VERSION}
CATEGORIES=	databases perl5

MAINTAINER=	obata@lins.jp
HOMEPAGE=	http://qdbm.sourceforge.net/
COMMENT=	Perl interface of QDBM

MY_SUBDIR=perl
BUILD_DIRS=	${MY_SUBDIR}
CONFIGURE_DIRS=	${MY_SUBDIR}

GNU_CONFIGURE=		yes
PERL5_CONFIGURE=        no
TEST_TARGET=            check

PERL5_PACKLIST= auto/Curia/.packlist auto/Depot/.packlist auto/Villa/.packlist
REPLACE_PERL=   ${MY_SUBDIR}/curia/plcrtest ${MY_SUBDIR}/depot/pldptest \
		${MY_SUBDIR}/villa/plvltest

.include "../../databases/qdbm/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.if defined(PTHREAD_TYPE) && ${PTHREAD_TYPE} != "none"
SUBST_CLASSES+=         pthread
SUBST_STAGE.pthread=    pre-configure
SUBST_FILES.pthread=    ${MY_SUBDIR}/configure
SUBST_SED.pthread=      -e 's|-lpthread|${PTHREAD_LIBS}|'
.endif
.include "../../mk/bsd.pkg.mk"
