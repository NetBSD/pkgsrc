# $NetBSD: Makefile,v 1.6 2003/01/19 01:29:20 wiz Exp $
#

DISTNAME=	watanabe-vf
PKGNAME=	watanabe-vfont-19930318
CATEGORIES=	fonts
MASTER_SITES=	ftp://ftp.kuis.kyoto-u.ac.jp/TeX/watanabe-jfonts/

MAINTAINER=	tech-pkg-ja@jp.netbsd.org
COMMENT=	Watanabe-vector Japanese font

USE_BUILDLINK2=	yes

EXTRACT_ONLY=	# empty
NO_CONFIGURE=	yes
NO_BUILD=	yes

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/fonts/watanabe_font
	${GTAR} Cxzf ${PREFIX}/share/fonts/watanabe_font \
		${_DISTDIR}/${DISTNAME}${EXTRACT_SUFX}
	${CHMOD} ${SHAREMODE} ${PREFIX}/share/fonts/watanabe_font/*
	${CHOWN} ${SHAREOWN}:${SHAREGRP} ${PREFIX}/share/fonts/watanabe_font/*

.include "../../mk/bsd.pkg.mk"
