# $NetBSD: Makefile,v 1.1.1.1 2002/05/31 13:00:27 seb Exp $
# FreeBSD Id: Makefile,v 1.9 1998/11/28 05:08:27 asami Exp $

DISTNAME=	sj3-2.0.1.20
PKGNAME=	sj3-lib-2.0.1.20
CATEGORIES=	japanese inputmethod
MASTER_SITES=	ftp://ftp.sony.co.jp/pub/unsupported/src/	\
		ftp://ftp.cs.titech.ac.jp/pub/japanese/sj3/

MAINTAINER=	tech-pkg-ja@jp.netbsd.org
COMMENT=	Japanese input method (library)

pre-configure:
	@${MV} ${WRKSRC}/Imakefile ${WRKSRC}/Imakefile.orig
	@${SED} -e 's|\(SUBDIRS = \).*\(sj3lib\).*|\1\2|'	\
		${WRKSRC}/Imakefile.orig > ${WRKSRC}/Imakefile

do-configure:
	@(cd ${WRKSRC}; ${X11BASE}/bin/xmkmf; ${MAKE} Makefiles)

.include "../../mk/bsd.pkg.mk"
