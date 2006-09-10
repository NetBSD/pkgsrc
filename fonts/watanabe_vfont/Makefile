# $NetBSD: Makefile,v 1.11 2006/09/10 12:19:04 obache Exp $
#

DISTNAME=	watanabe-vf
PKGNAME=	watanabe-vfont-19930318
CATEGORIES=	fonts
MASTER_SITES=	ftp://ftp.kuis.kyoto-u.ac.jp/TeX/watanabe-jfonts/

MAINTAINER=	tech-pkg-ja@jp.NetBSD.org
COMMENT=	Watanabe-vector Japanese font

EXTRACT_ONLY=	# empty
NO_CONFIGURE=	yes
NO_BUILD=	yes

USE_TOOLS+=	tar

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/fonts/watanabe_font
	cd ${PREFIX}/share/fonts/watanabe_font \
		&& ${TAR} xzf ${_DISTDIR}/${DISTNAME}${EXTRACT_SUFX}
	${CHMOD} ${SHAREMODE} ${PREFIX}/share/fonts/watanabe_font/*
	${CHOWN} ${SHAREOWN}:${SHAREGRP} ${PREFIX}/share/fonts/watanabe_font/*

.include "../../mk/bsd.pkg.mk"
