# $NetBSD: Makefile,v 1.14 2015/03/15 15:29:46 tnn Exp $
#

DISTNAME=	watanabe-vf
PKGNAME=	watanabe-vfont-19930318
CATEGORIES=	fonts
MASTER_SITES=	# ftp://ftp.kuis.kyoto-u.ac.jp/TeX/watanabe-jfonts/

MAINTAINER=	tech-pkg-ja@jp.NetBSD.org
COMMENT=	Watanabe-vector Japanese font

PKG_DESTDIR_SUPPORT=	destdir

EXTRACT_ONLY=	# empty
NO_CONFIGURE=	yes
NO_BUILD=	yes

USE_TOOLS+=	gzip tar

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/fonts/watanabe_font
	cd ${DESTDIR}${PREFIX}/share/fonts/watanabe_font \
		&& ${TAR} xzf ${_DISTDIR}/${DISTNAME}${EXTRACT_SUFX}
	${CHMOD} ${SHAREMODE} ${DESTDIR}${PREFIX}/share/fonts/watanabe_font/*
	${CHOWN} ${SHAREOWN}:${SHAREGRP} \
		${DESTDIR}${PREFIX}/share/fonts/watanabe_font/*

.include "../../mk/bsd.pkg.mk"
