# $NetBSD: Makefile,v 1.7 2005/03/24 21:12:55 wiz Exp $

DISTNAME=	sj3-2.0.1.20
PKGNAME=	sj3-lib-2.0.1.20
PKGREVISION=	1
CATEGORIES=	japanese inputmethod
MASTER_SITES=	ftp://ftp.sony.co.jp/pub/unsupported/src/	\
		ftp://ftp.cs.titech.ac.jp/pub/japanese/sj3/

MAINTAINER=	tech-pkg-ja@jp.NetBSD.org
COMMENT=	Japanese input method (library)

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=	YES

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
