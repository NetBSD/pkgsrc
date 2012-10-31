# $NetBSD: Makefile,v 1.3 2012/10/31 11:17:03 asau Exp $
#

DISTNAME=	gprbuild-aux-${SNAPSHOT}
CATEGORIES=	devel
MASTER_SITES=	http://downloads.dragonlace.net/src/ \
		http://dragonlace.mirrors.ada.cx/src/
DISTFILES=	gprbuild-gpl-2012-src.tgz

MAINTAINER=	draco@marino.st
HOMEPAGE=	http://www.adacore.com/home/products/gnatpro/toolsuite/gprbuild/
COMMENT=	Adacore multi-language software build tool
LICENSE=	gnu-gpl-v3

SNAPSHOT=		20120510
GNU_CONFIGURE=		yes
USE_LANGUAGES=		c ada
USE_TOOLS=		gmake
MAKE_ENV+=		ADA_PROJECT_PATH=${PREFIX}/lib/gnat
CONFIGURE_ENV+=		ADA_PROJECT_PATH=${PREFIX}/lib/gnat
WRKSRC=			${WRKDIR}/gprbuild-2012-src

SUBST_CLASSES+= 	xml
SUBST_STAGE.xml=	pre-configure
SUBST_MESSAGE.xml=	Edit compilers.xml to support lang/gcc-aux runtime
SUBST_FILES.xml=	share/gprconfig/compilers.xml
SUBST_SED.xml=		-e "s,@AUXPREFIX@,${PREFIX}/gcc-aux,"

.include "../../textproc/xmlada/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
