# $NetBSD: Makefile,v 1.2 1999/08/02 11:28:35 sakamoto Exp $
# FreeBSD Id: Makefile,v 1.9 1998/11/28 05:08:27 asami Exp $

DISTNAME=	sj3-2.0.1.20
PKGNAME=	sj3-lib-2.0.1.20
CATEGORIES=	japanese
MASTER_SITES=	ftp://ftp.sony.co.jp/pub/unsupported/src/	\
		ftp://ftp.cs.titech.ac.jp/pub/japanese/sj3/

MAINTAINER=	tech-pkg-ja@jp.netbsd.org

pre-configure:
	@${MV} ${WRKSRC}/Imakefile ${WRKSRC}/Imakefile.orig
	@${SED} -e 's|\(SUBDIRS = \).*\(sj3lib\).*|\1\2|'	\
		${WRKSRC}/Imakefile.orig > ${WRKSRC}/Imakefile

do-configure:
	@(cd ${WRKSRC}; xmkmf; ${MAKE} Makefiles)

.include "../../mk/bsd.pkg.mk"
