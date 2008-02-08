# $NetBSD: Makefile,v 1.34 2008/02/08 03:50:07 bjs Exp $

DISTNAME=	nasm-2.01
PKGREVISION=	1
CATEGORIES=	devel lang
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=nasm/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://nasm.sourceforge.net/
COMMENT=	General-purpose x86 assembler

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=		gmake makeinfo perl
GCC_REQD+=		3.0
GNU_CONFIGURE=		yes

INFO_FILES=		yes
BUILD_TARGET=		everything
INSTALL_TARGET=		install_everything

INSTALL_ENV+=	INSTALLROOT=${DESTDIR}

MAKE_ENV+=	PERL5=${PERL5:Q}

AUTO_MKDIRS=	yes

.include "../../mk/compiler.mk"

.if !empty(CC_VERSION:Mgcc-2*)
BUILDLINK_TRANSFORM+=	rm:-std=c99
.endif

.include "../../mk/bsd.pkg.mk"
