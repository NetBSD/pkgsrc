# $NetBSD: Makefile,v 1.1 2015/04/09 09:35:05 wiz Exp $

V=		150406
DISTNAME=	heirloom-doctools-${V}
CATEGORIES=	textproc
MASTER_SITES=	http://github.com/n-t-roff/heirloom-doctools/releases/download/${V}/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	carsten.kunze@arcor.de
HOMEPAGE=	http://n-t-roff.github.io/heirloom/doctools.html
COMMENT=	Modernized troff implementation
LICENSE=	cddl-1.0

USE_LANGUAGES=	c c++
MAKE_JOBS_SAFE=	no

MAKE_FLAGS =	CC="${CC}" \
		CCC="${CXX}" \
		CFLAGS="${CFLAGS}" \
		RANLIB=ranlib \
		INSTALL=install \
		ROOT=${DESTDIR} \
		BINDIR=${PREFIX}/heirloom-doctools/bin \
		MANDIR=${PREFIX}/heirloom-doctools/man \
		LIBDIR=${PREFIX}/libexec/heirloom-doctools \
		MACDIR=${PREFIX}/share/heirloom-doctools/tmac \
		FNTDIR=${PREFIX}/share/heirloom-doctools/font \
		TABDIR=${PREFIX}/share/heirloom-doctools/nterm \
		HYPDIR=${PREFIX}/share/heirloom-doctools/hyphen \
		PUBDIR=${PREFIX}/share/heirloom-doctools/pub \
		PSTDIR=${PREFIX}/share/heirloom-doctools/font/devpost/postscript \
		REFDIR=${PREFIX}/libexec/heirloom-doctools/reftools

MAKE_FILE=	makefile
BUILD_TARGET=	dummy

.include "../../mk/bsd.pkg.mk"
