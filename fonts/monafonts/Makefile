# $NetBSD: Makefile,v 1.2 2002/10/31 13:59:24 toshii Exp $

DISTNAME=	monafont-2.21
PKGNAME=	${DISTNAME:S/font/fonts/}
CATEGORIES=	fonts japanese
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=monafont/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	uebayasi@soum.co.jp
HOMEPAGE=	http://monafont.sourceforge.net/
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

post-extract:
	${MKDIR} ${WRKSRC}/dist

.include "../../mk/bsd.pkg.install.mk"
.include "../../mk/bsd.pkg.mk"
