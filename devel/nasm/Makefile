# $NetBSD: Makefile,v 1.59 2018/11/12 14:40:21 jperkin Exp $

DISTNAME=	nasm-2.13.03
PKGREVISION=	1
CATEGORIES=	devel lang
MASTER_SITES=	http://www.nasm.us/pub/nasm/releasebuilds/${PKGVERSION_NOREV}/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.nasm.us/
COMMENT=	General-purpose x86 assembler
LICENSE=	2-clause-bsd

USE_TOOLS+=		gmake makeinfo perl
GNU_CONFIGURE=		yes

BUILD_TARGET=		everything
INSTALL_TARGET=		install_everything

INSTALL_ENV+=	INSTALLROOT=${DESTDIR}
MAKE_ENV+=	PERL5=${PERL5:Q}

CTF_SUPPORTED=	no # https://smartos.org/bugview/OS-6510

.include "../../mk/bsd.pkg.mk"
