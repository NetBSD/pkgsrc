# $NetBSD: Makefile,v 1.18 2005/03/08 18:51:06 xtraeme Exp $

DISTNAME=	nasm-0.98.39
CATEGORIES=	devel lang
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=nasm/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://nasm.sourceforge.net/
COMMENT=	General-purpose x86 assembler

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=		yes
USE_GNU_TOOLS+=		make
GCC_REQD+=		3.0
USE_MAKEINFO=		yes
USE_PERL5=		build
GNU_CONFIGURE=		yes

INFO_FILES=		nasm.info
BUILD_TARGET=		everything
INSTALL_TARGET=		install_everything

MAKE_ENV+=	PERL5="${PERL5}"			\
		INSTALL_DATA_DIR="${INSTALL_DATA_DIR}"

INSTALLATION_DIRS=	bin info man/man1 share/doc/html

.include "../../mk/compiler.mk"

.if !empty(CC_VERSION:Mgcc-2*)
SUBST_CLASSES+=     c99
SUBST_STAGE.c99=    pre-configure
SUBST_FILES.c99=    configure
SUBST_SED.c99=      -e "s,\-std=c99,,g"
SUBST_MESSAGE.c99=  "Fixing configure script."
.endif

.include "../../mk/bsd.pkg.mk"
