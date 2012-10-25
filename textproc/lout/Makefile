# $NetBSD: Makefile,v 1.17 2012/10/25 06:56:06 asau Exp $

DISTNAME=	lout-3.38
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=lout/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://lout.sourceforge.net/
COMMENT=	Basser Lout, a TeX/troff-like formatter with PostScript/PDF output
LICENSE=	gnu-gpl-v3

PLIST_SRC=	${WRKDIR}/.PLIST_SRC
INSTALL_TARGET=	allinstall
INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1 share/doc

do-configure:
	${MV} ${WRKSRC}/makefile ${WRKSRC}/makefile.in
	${SED} -e "s,@PREFIX@,${PREFIX}," <${WRKSRC}/makefile.in >${WRKSRC}/Makefile

post-install:
	${CAT} ${PKGDIR}/PLIST.pre >${PLIST_SRC}
	(cd ${DESTDIR}${PREFIX}; ${FIND} share/doc/lout -type f -print >>${PLIST_SRC})
	(cd ${DESTDIR}${PREFIX}; ${FIND} share/lout -type f -print >>${PLIST_SRC})

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
