# $NetBSD: Makefile,v 1.9 2005/09/28 18:22:11 rillig Exp $

DISTNAME=	sj3-2.0.1.20
PKGNAME=	sj3-lib-2.0.1.20
PKGREVISION=	2
CATEGORIES=	japanese inputmethod
MASTER_SITES=	ftp://ftp.sony.co.jp/pub/unsupported/src/	\
		ftp://ftp.cs.titech.ac.jp/pub/japanese/sj3/

MAINTAINER=	tech-pkg-ja@jp.NetBSD.org
COMMENT=	Japanese input method (library)

PKG_INSTALLATION_TYPES=	overwrite pkgviews


.include "../../mk/bsd.prefs.mk"

MAKE_ENV+=	IMDICTDIR=${IMDICTDIR}

pre-configure:
	@${MV} ${WRKSRC}/Imakefile ${WRKSRC}/Imakefile.orig
	@${SED} -e 's|\(SUBDIRS = \).*\(sj3lib\).*|\1\2|'	\
		${WRKSRC}/Imakefile.orig > ${WRKSRC}/Imakefile

do-configure:
	@(cd ${WRKSRC}; ${XMKMF_CMD}; ${MAKE} Makefiles)

.include "../../devel/nbitools/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
