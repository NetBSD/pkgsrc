# $NetBSD: Makefile,v 1.55 2017/08/11 22:17:34 maya Exp $

DISTNAME=	nasm-2.13.01
CATEGORIES=	devel lang
MASTER_SITES=	http://www.nasm.us/pub/nasm/releasebuilds/${PKGVERSION_NOREV}/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.nasm.us/
COMMENT=	General-purpose x86 assembler
LICENSE=	2-clause-bsd

#AUTO_MKDIRS=		yes

USE_TOOLS+=		gmake makeinfo perl
GNU_CONFIGURE=		yes

BUILD_TARGET=		everything
INSTALL_TARGET=		install_everything

INSTALL_ENV+=	INSTALLROOT=${DESTDIR}
MAKE_ENV+=	PERL5=${PERL5:Q}

.include "../../mk/bsd.pkg.mk"
