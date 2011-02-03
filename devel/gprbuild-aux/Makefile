# $NetBSD: Makefile,v 1.1.1.1 2011/02/03 19:04:02 drochner Exp $
#

DISTNAME=	gprbuild-aux-${SNAPSHOT}
CATEGORIES=	devel
MASTER_SITES=	http://downloads.dragonlace.net/src/ \
		http://dragonlace.mirrors.ada.cx/src/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	draco@marino.st
HOMEPAGE=	http://www.adacore.com/home/products/gnatpro/toolsuite/gprbuild/
COMMENT=	Adacore multi-language software build tool
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir
SNAPSHOT=		20101120
GNU_CONFIGURE=		yes
USE_LANGUAGES=		c # Ada is not option.
USE_TOOLS=		gmake
MAKE_ENV+=		ADA_PROJECT_PATH=${PREFIX}/lib/gnat
#CONFIGURE_ENV+=		CC=gnatgcc

# no special configuration options necessary
pre-configure:
	# explicitly request GNAT-AUX compiler (required by XML/Ada too)
	# It is done here to fool tough pkgsrc compiler checks
	${SETENV} CC=gnatgcc

do-wrapper:
	# GPRbuild has a linkage problem while using standard wrappers
	${ECHO} "##  Wrappers are intentionally disabled  ##"

.include "../../textproc/xmlada/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
