# $NetBSD: Makefile,v 1.5 2014/05/09 12:14:58 marino Exp $
#

DISTNAME=	gprbuild-aux-${SNAPSHOT}
CATEGORIES=	devel
MASTER_SITES=	http://downloads.dragonlace.net/src/ \
		http://dragonlace.mirrors.ada.cx/src/
DISTFILES=	gprbuild-gpl-${YEAR}-src.tgz

MAINTAINER=	draco@marino.st
HOMEPAGE=	http://www.adacore.com/home/products/gnatpro/toolsuite/gprbuild/
COMMENT=	Adacore multi-language software build tool
LICENSE=	gnu-gpl-v3

SNAPSHOT=		20130416
YEAR=			2013
GNU_CONFIGURE=		yes
USE_LANGUAGES=		c ada
USE_TOOLS=		gmake
MAKE_ARGS+=		BUILD=production
MAKE_ARGS+=		PROCESSORS=${MAKE_JOBS:U1:Q}
MAKE_ENV+=		ADA_PROJECT_PATH=${PREFIX}/lib/gnat
CONFIGURE_ENV+=		ADA_PROJECT_PATH=${PREFIX}/lib/gnat
WRKSRC=			${WRKDIR}/gprbuild-${YEAR}-src

SUBST_CLASSES+= 	xml
SUBST_STAGE.xml=	pre-configure
SUBST_MESSAGE.xml=	Edit compilers.xml to support lang/gcc-aux runtime
SUBST_FILES.xml=	share/gprconfig/compilers.xml
SUBST_SED.xml=		-e "s,@AUXPREFIX@,${PREFIX}/gcc-aux,"

do-build:
	# Recreate the do-build target without the -J parameter
	# It interferes with the PROCESSORS configure argument
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} gmake ${MAKE_ARGS} all

.include "../../textproc/xmlada/buildlink3.mk"
.include "../../lang/gnat_util/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
