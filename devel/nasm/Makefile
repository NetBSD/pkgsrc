# $NetBSD: Makefile,v 1.9 2003/09/17 16:40:12 jmmv Exp $
#

DISTNAME=	nasm-0.98.37
CATEGORIES=	devel lang
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=nasm/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://nasm.sourceforge.net/
COMMENT=	General-purpose x86 assembler

ALL_TARGET=	everything
INSTALL_TARGET=	install_everything
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_PERL5=	build
USE_MAKEINFO=	YES
INFO_FILES=	nasm.info

MAKE_ENV+=	PERL5="${PERL5}"			\
		INSTALL_DATA_DIR="${INSTALL_DATA_DIR}"

.include "../../mk/bsd.pkg.mk"
