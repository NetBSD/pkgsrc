# $NetBSD: Makefile,v 1.15 2005/02/25 11:42:17 adam Exp $

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
USE_MAKEINFO=		yes
USE_PERL5=		build
GNU_CONFIGURE=		yes

INFO_FILES=		nasm.info
BUILD_TARGET=		everything
INSTALL_TARGET=		install_everything

MAKE_ENV+=	PERL5="${PERL5}"			\
		INSTALL_DATA_DIR="${INSTALL_DATA_DIR}"

INSTALLATION_DIRS=	bin info man/man1 share/doc/html

.include "../../mk/bsd.pkg.mk"
