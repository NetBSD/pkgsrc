# $NetBSD: Makefile,v 1.8 2003/03/15 16:15:12 wiz Exp $
#

DISTNAME=	nasm-0.98.36
CATEGORIES=	devel lang
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=nasm/}

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://nasm.sourceforge.net/
COMMENT=	General-purpose x86 assembler (development version)

ALL_TARGET=	everything
INSTALL_TARGET=	install_everything
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_PERL5=	build
INFO_FILES=	nasm.info
TEXINFO_OVERRIDE=	YES
TEXINFO_PATTERNS+=	Makefile

MAKE_ENV+=	PERL5="${PERL5}"			\
		INSTALL_DATA_DIR="${INSTALL_DATA_DIR}"

.include "../../mk/texinfo.mk"
.include "../../mk/bsd.pkg.mk"
