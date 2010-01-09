# $NetBSD: Makefile,v 1.12 2010/01/09 11:37:10 obache Exp $

DISTNAME=	sj3-2.0.1.20
PKGNAME=	sj3-lib-2.0.1.20
PKGREVISION=	3
CATEGORIES=	japanese inputmethod
MASTER_SITES=	ftp://ftp.sony.co.jp/pub/unsupported/src/	\
		ftp://ftp.cs.titech.ac.jp/pub/japanese/sj3/

MAINTAINER=	tech-pkg-ja@jp.NetBSD.org
COMMENT=	SJ3 Japanese input method library

PKG_DESTDIR_SUPPORT=	destdir

USE_TOOLS+=	itools
USE_IMAKE=	yes
MAKE_ENV+=	IMDICTDIR=${IMDICTDIR:Q}

pre-configure:
	@${MV} ${WRKSRC}/Imakefile ${WRKSRC}/Imakefile.orig
	@${SED} -e 's|\(SUBDIRS = \).*\(sj3lib\).*|\1\2|'	\
		${WRKSRC}/Imakefile.orig > ${WRKSRC}/Imakefile

.include "../../mk/bsd.pkg.mk"
