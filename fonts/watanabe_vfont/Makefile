# $NetBSD: Makefile,v 1.2 2000/08/02 20:42:44 darcy Exp $
#

DISTNAME=	watanabe-vf
PKGNAME=	watanabe-vfont-19930318
CATEGORIES=	fonts
MASTER_SITES=	ftp://ftp.kuis.kyoto-u.ac.jp/TeX/watanabe-jfonts/
EXTRACT_SUFX=	.tar.gz

MAINTAINER=	tech-pkg-ja@jp.netbsd.org

EXTRACT_ONLY=	# empty
NO_PATCH=	yes
NO_CONFIGURE=	yes
NO_BUILD=	yes

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/fonts/watanabe_font
	${GTAR} Cxzf ${PREFIX}/share/fonts/watanabe_font \
		${_DISTDIR}/${DISTNAME}${EXTRACT_SUFX}
	${CHMOD} ${SHAREMODE} ${PREFIX}/share/fonts/watanabe_font/*
	${CHOWN} ${SHAREOWN}:${SHAREGRP} ${PREFIX}/share/fonts/watanabe_font/*

.include "../../mk/bsd.pkg.mk"
