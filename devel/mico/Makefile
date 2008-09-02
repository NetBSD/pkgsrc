# $NetBSD: Makefile,v 1.1.1.1 2008/09/02 07:18:26 tonnerre Exp $
#

DISTNAME=		mico-2.3.12
CATEGORIES=		devel
MASTER_SITES=		http://www.mico.org/
HOMEPAGE=		http://www.mico.org/
WRKSRC=			${WRKDIR}/mico

MAINTAINER=		tonnerre@NetBSD.org
COMMENT=		High performance and rubustness CORBA ORB

USE_TOOLS+=		gmake msgfmt intltool
GNU_CONFIGURE=		YES
USE_LANGUAGES=		c c++

SUBST_CLASSES+=		exampledir
SUBST_STAGE.exampledir=	post-patch
SUBST_MESSAGE.exampledir=	Fixing up examples directory path
SUBST_FILES.exampledir=		demo/ccm/Makefile demo/Makefile demo/MakeVars
SUBST_FILES.exampledir+=	demo/csiv2/Makefile demo/csiv2/interop/Makefile
SUBST_FILES.exampledir+=	demo/dispatcher/Makefile demo/interop/Makefile
SUBST_FILES.exampledir+=	demo/interop/jboss/jdk1.3.x/cart-ejb/Makefile
SUBST_FILES.exampledir+=	demo/interop/jboss/jdk1.3.x/Makefile
SUBST_FILES.exampledir+=	demo/interop/jboss/jdk1.3.x/converter-ejb/Makefile
SUBST_FILES.exampledir+=	demo/interop/jboss/jdk1.3.x/corba-friendly-ejb/Makefile
SUBST_FILES.exampledir+=	demo/interop/jboss/Makefile
SUBST_FILES.exampledir+=	demo/interop/jboss/jdk1.4.x/cart-ejb/Makefile
SUBST_FILES.exampledir+=	demo/interop/jboss/jdk1.4.x/Makefile
SUBST_FILES.exampledir+=	demo/interop/jboss/jdk1.4.x/converter-ejb/Makefile
SUBST_FILES.exampledir+=	demo/interop/jboss/jdk1.4.x/corba-friendly-ejb/Makefile
SUBST_FILES.exampledir+=	demo/ltp/Makefile demo/mt/Makefile
SUBST_FILES.exampledir+=	demo/obv/Makefile demo/pi/Makefile
SUBST_FILES.exampledir+=	demo/poa/Makefile demo/security/Makefile
SUBST_FILES.exampledir+=	demo/services/Makefile demo/siegel/Makefile
SUBST_FILES.exampledir+=	demo/services/wireless/Makefile
SUBST_SED.exampledir=		-e "s@(INSTDIR)/doc/mico/examples@(SHARED_INSTDIR)/examples/${PKGBASE}@g"

.include "../../textproc/scrollkeeper/omf.mk"
.include "../../mk/bsd.pkg.mk"
