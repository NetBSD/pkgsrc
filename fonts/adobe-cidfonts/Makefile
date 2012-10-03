# $NetBSD: Makefile,v 1.11 2012/10/03 18:28:16 asau Exp $

DISTNAME=	adobe-cidfonts-20000901
CATEGORIES=	fonts
MASTER_SITES=	ftp://ftp.oreilly.com/pub/examples/nutshell/cjkv/adobe/samples/

MAINTAINER=	pkgsrc-users@NetBSD.org
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

EXTRACT_ONLY=	# empty
NO_CONFIGURE=	yes
NO_BUILD=	yes

RESOURCESUBDIR=	share/Adobe/Resource
RESOURCEDIR=	${PREFIX}/${RESOURCESUBDIR}

GENERATE_PLIST=								\
	for f in ${DISTFILES:O:u}; do					\
		${ECHO} ${RESOURCESUBDIR}/CIDFont/$$f;			\
	done;

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${RESOURCEDIR}/CIDFont
	for file in ${DISTFILES}; do					\
		${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/$${file}	\
			${DESTDIR}${RESOURCEDIR}/CIDFont;		\
	done

.include "../../mk/bsd.pkg.mk"
