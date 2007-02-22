# $NetBSD: Makefile,v 1.11 2007/02/22 19:24:01 wiz Exp $
#

DISTNAME=	lout-3.26
PKGREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=lout/}

MAINTAINER=	tsarna@NetBSD.org
HOMEPAGE=	http://lout.sourceforge.net/
COMMENT=	Basser Lout, a TeX/troff-like formatter with PostScript/PDF output

PLIST_SRC=	${WRKDIR}/.PLIST_SRC
INSTALL_TARGET=	allinstall

do-configure:
	${MV} ${WRKSRC}/makefile ${WRKSRC}/makefile.in
	${SED} -e "s,@PREFIX@,${PREFIX}," <${WRKSRC}/makefile.in >${WRKSRC}/Makefile

post-install:
	${CAT} ${PKGDIR}/PLIST.pre >${PLIST_SRC}
	(cd ${PREFIX}; ${FIND} share/doc/lout -type f -print >>${PLIST_SRC})
	(cd ${PREFIX}; ${FIND} share/lout -type f -print >>${PLIST_SRC})
	${ECHO} "@unexec ${RM} -rf %D/share/doc/lout" >>${PLIST_SRC}
	(cd ${PREFIX}; ${FIND} -d share/lout -type d -print | \
	${SED} -e "s/^/@dirrm /" >>${PLIST_SRC})

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
