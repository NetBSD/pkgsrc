# $NetBSD: Makefile,v 1.11 2004/01/05 11:45:05 jlam Exp $
#

DISTNAME=	nasm-0.98.38
CATEGORIES=	devel lang
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=nasm/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://nasm.sourceforge.net/
COMMENT=	General-purpose x86 assembler

PKG_INSTALLATION_TYPES=	overwrite pkgviews
USE_BUILDLINK3=	YES

ALL_TARGET=	everything
INSTALL_TARGET=	install_everything
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_PERL5=	build
USE_MAKEINFO=	YES
INFO_FILES=	nasm.info

MAKE_ENV+=	PERL5="${PERL5}"			\
		INSTALL_DATA_DIR="${INSTALL_DATA_DIR}"

INSTALLATION_DIRS=	bin info man/man1 share/doc/html

.include "../../mk/bsd.pkg.mk"
