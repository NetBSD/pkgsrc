# $NetBSD: Makefile,v 1.4 2002/10/21 14:28:53 wiz Exp $
# FreeBSD Id: Makefile,v 1.9 1998/11/28 05:08:27 asami Exp $

DISTNAME=	sj3-2.0.1.20
PKGNAME=	sj3-lib-2.0.1.20
PKGREVISION=	1
CATEGORIES=	japanese inputmethod
MASTER_SITES=	ftp://ftp.sony.co.jp/pub/unsupported/src/	\
		ftp://ftp.cs.titech.ac.jp/pub/japanese/sj3/

MAINTAINER=	tech-pkg-ja@jp.netbsd.org
COMMENT=	Japanese input method (library)

USE_BUILDLINK2=	YES

.include "../../mk/bsd.prefs.mk"

MAKE_ENV+=	IMDICTDIR=${IMDICTDIR}

pre-configure:
	@${MV} ${WRKSRC}/Imakefile ${WRKSRC}/Imakefile.orig
	@${SED} -e 's|\(SUBDIRS = \).*\(sj3lib\).*|\1\2|'	\
		${WRKSRC}/Imakefile.orig > ${WRKSRC}/Imakefile

do-configure:
	@(cd ${WRKSRC}; ${XMKMF_CMD}; ${MAKE} Makefiles)

.include "../../devel/nbitools/nbitools.mk"
.include "../../mk/bsd.pkg.mk"
