# $NetBSD: Makefile,v 1.1.1.1 2002/03/24 03:10:58 uebayasi Exp $

DISTNAME=	monafonts-2.1
CATEGORIES=	fonts japanese
MASTER_SITES=   http://members.tripod.co.jp/s42335/mona/dist/
EXTRACT_SUFX=	.tar.bz2.bin

MAINTAINER=	uebayasi@soum.co.jp
HOMEPAGE=	http://members.tripod.co.jp/s42335/mona/
COMMENT=	Japanese fonts for "Mona" seen at 2ch.net

USE_X11BASE=	# Defined
USE_PERL5=	# Defined
ALL_TARGET=	bdf
MAKE_FLAGS+=	SED_CMD=${SED:Q}
MAKE_FLAGS+=	PERL_CMD=${PERL5:Q}
MAKE_FLAGS+=	GZIP_CMD=${GZIP_CMD:Q}

INSTALL_TMPL=	${FILESDIR}/install
DEINSTALL_TMPL=	${FILESDIR}/deinstall
FILES_SUBST+=	X11FONTSSUBDIR=local

.include "../../mk/bsd.pkg.install.mk"
.include "../../mk/bsd.pkg.mk"
