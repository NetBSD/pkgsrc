# $NetBSD: Makefile,v 1.3 2004/04/24 22:46:10 jlam Exp $

DISTNAME=	adobe-cidfonts-20000901
CATEGORIES=	fonts
MASTER_SITES=	ftp://ftp.oreilly.com/pub/examples/nutshell/cjkv/adobe/samples/

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	Adobe CID-keyed O'Reilly fonts for CJK

DIST_SUBDIR=	${PKGBASE}
DISTFILES=	MOEKai-Regular MOEKai-Regular.afm
DISTFILES+=	MOESung-Regular MOESung-Regular.afm
DISTFILES+=	Munhwa-Bold Munhwa-Bold.afm
DISTFILES+=	Munhwa-Regular Munhwa-Regular.afm
DISTFILES+=	MunhwaGothic-Bold MunhwaGothic-Bold.afm
DISTFILES+=	MunhwaGothic-Regular MunhwaGothic-Regular.afm
DISTFILES+=	MunhwaGungSeo-Bold MunhwaGungSeo-Bold.afm
DISTFILES+=	MunhwaGungSeo-Light MunhwaGungSeo-Light.afm
DISTFILES+=	MunhwaGungSeoHeulim-Bold MunhwaGungSeoHeulim-Bold.afm
DISTFILES+=	MunhwaGungSeoHeulim-Light MunhwaGungSeoHeulim-Light.afm
DISTFILES+=	MunhwaHoonMin-Regular MunhwaHoonMin-Regular.afm
DISTFILES+=	WadaGo-Bold WadaGo-Bold.afm
DISTFILES+=	WadaMaruGo-Regular WadaMaruGo-Regular.afm
DISTFILES+=	WadaMaruGo-RegularH WadaMaruGo-RegularH.afm
DISTFILES+=	WadaMin-Bold WadaMin-Bold.afm
DISTFILES+=	WadaMin-Regular WadaMin-Regular.afm
DISTFILES+=	WadaMin-RegularH WadaMin-RegularH.afm

USE_BUILDLINK2=	# defined
EXTRACT_ONLY=	# empty
NO_CONFIGURE=	# defined
NO_BUILD=	# defined

RESOURCEDIR=	${PREFIX}/share/Adobe/Resource

PLIST_SRC=	${WRKDIR}/.PLIST_SRC

do-install:
	${INSTALL_DATA_DIR} ${RESOURCEDIR}/CIDFont
	for file in ${DISTFILES}; do					\
		${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/$${file}	\
			${RESOURCEDIR}/CIDFont;				\
	done
	${CAT} ${.CURDIR}/PLIST > ${PLIST_SRC}
	( for file in ${DISTFILES}; do					\
		${ECHO} ${RESOURCEDIR:S/^${PREFIX}\///}/CIDFont/$${file}; \
	  done;								\
	) | ${SORT} -u >> ${PLIST_SRC}
	( ${ECHO} "@dirrm ${RESOURCEDIR:S/^${PREFIX}\///}/CIDFont";	\
	  ${ECHO} "@unexec ${RMDIR} -p %D/${RESOURCEDIR:S/^${PREFIX}\///} 2>/dev/null || ${TRUE}";	\
	) >> ${PLIST_SRC}

.include "../../mk/bsd.pkg.mk"
