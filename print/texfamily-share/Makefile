# $NetBSD: Makefile,v 1.2 2002/09/16 08:48:29 uebayasi Exp $

DISTNAME=	TeXfamily-share-1.2.1
PKGREVISION=	3
CATEGORIES=	japanese print
MASTER_SITES=	ftp://ftp.math.s.chiba-u.ac.jp/tex/texfam-1.2/ \
		ftp://ftp.math.s.chiba-u.ac.jp/tex/texfam-1.2.1/ \
		ftp://ftp.ascii.co.jp/pub/TeX/ascii-ptex/tetex/ \
		ftp://ftp.ascii.co.jp/pub/TeX/ascii-ptex/jvf/
DISTFILES=	ptex-texmf-2.0${EXTRACT_SUFX} \
		texfam-texmf-latex209${EXTRACT_SUFX} \
		texfam-texmf-j1.9${EXTRACT_SUFX} \
		texfam-texmf-j1.9.1${EXTRACT_SUFX} \
		texfam-texmf-m0.8${EXTRACT_SUFX} \
		mulfonts-vf${EXTRACT_SUFX} mulfonts-subtfm${EXTRACT_SUFX} \
		jis${EXTRACT_SUFX} nmin-ngoth${EXTRACT_SUFX} \
		standard${EXTRACT_SUFX} morisawa${EXTRACT_SUFX}

MAINTAINER=	kei@netbsd.org
COMMENT=	Machine-independent part of TeXfamily (pTeX, JTeX, MuLTeX)

DEPENDS+=	teTeX>=1.0.7nb1:../../print/teTeX

DIST_SUBDIR=	TeXfamily
WRKSRC=		${WRKDIR}
EXTRACT_ONLY=	jis${EXTRACT_SUFX} nmin-ngoth${EXTRACT_SUFX} \
		standard${EXTRACT_SUFX} morisawa${EXTRACT_SUFX}
NO_PATCH=	yes
NO_CONFIGURE=	yes
NO_BUILD=	yes
NO_MTREE=	yes
PLIST_SRC=	${WRKDIR}/PLIST_SRC

do-install:
	@${INSTALL_DATA_DIR} ${LOCALBASE}/share/texmf.local
.for f in ptex-texmf-2.0 texfam-texmf-latex209 texfam-texmf-j1.9 \
    texfam-texmf-j1.9.1 texfam-texmf-m0.8 \
    mulfonts-vf mulfonts-subtfm jis nmin-ngoth standard morisawa
	@${GTAR} -plzx -C ${LOCALBASE}/share/texmf.local \
		-f ${DISTDIR}/${DIST_SUBDIR}/${f}${EXTRACT_SUFX} \
		--exclude=ls-R
.endfor
	@${INSTALL_DATA_DIR} ${LOCALBASE}/share/texmf.local/doc/fonts
	@${GTAR} Ccf ${WRKDIR}/morisawa/tfm/ptex - . | \
		${GTAR} Cxf ${LOCALBASE}/share/texmf.local/fonts/tfm/ptex -
.for font in jis nmin-ngoth standard morisawa
	@${GTAR} Ccf ${WRKDIR}/${font} - tfm/dvips vf | \
		${GTAR} Cxf ${LOCALBASE}/share/texmf.local/fonts -
	@${INSTALL_DATA} ${WRKDIR}/${font}/README.txt \
		${LOCALBASE}/share/texmf.local/doc/fonts/README.${font}
.endfor

post-install:
	@cd ${LOCALBASE}; \
	 ${CAT} ${PKGDIR}/PLIST > ${PLIST_SRC}; \
	 ${FIND} share/texmf.local -type f|sort >> ${PLIST_SRC}; \
	 for LINK in `${FIND} share/texmf.local -type l`; do \
		set - X `${FILE} $$LINK`; \
		${ECHO} "@exec ${LN} -s $$6 %D/$$LINK" >>${PLIST_SRC}; \
		${ECHO} "@unexec ${RM} -f %D/$$LINK" >>${PLIST_SRC}; \
	 done; \
	 for DIR in `${FIND} share/texmf.local -type d | sort -r`; do \
	 	if [ -z "`ls $$DIR`" ]; then \
			${ECHO} "@exec ${MKDIR} %D/$$DIR" >>${PLIST_SRC}; \
	 	fi; \
	 	${ECHO} "@dirrm $$DIR" >>${PLIST_SRC}; \
	 done

.include "../../mk/bsd.pkg.mk"
