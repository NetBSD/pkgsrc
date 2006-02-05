# $NetBSD: Makefile,v 1.26 2006/02/05 23:08:48 joerg Exp $

DISTNAME=	nasm-0.98.39
PKGREVISION=	2
CATEGORIES=	devel lang
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=nasm/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://nasm.sourceforge.net/
COMMENT=	General-purpose x86 assembler

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_TOOLS+=		gmake perl
GCC_REQD+=		3.0
USE_MAKEINFO=		yes
GNU_CONFIGURE=		yes

INFO_FILES=		nasm.info
BUILD_TARGET=		everything
INSTALL_TARGET=		install_everything

MAKE_ENV+=	PERL5=${PERL5:Q}			\
		INSTALL_DATA_DIR=${INSTALL_DATA_DIR:Q}

INSTALLATION_DIRS=	bin info ${PKGMANDIR}/man1 share/doc/html

.include "../../mk/compiler.mk"

.if !empty(CC_VERSION:Mgcc-2*)
BUILDLINK_TRANSFORM+=   rm:-std=c99
.endif

.include "../../mk/bsd.pkg.mk"
