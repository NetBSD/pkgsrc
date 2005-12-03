# $NetBSD: Makefile,v 1.15 2005/12/03 20:11:40 wiz Exp $

DISTNAME=	TeXfamily-share-1.2.1
PKGREVISION=	5
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

MAINTAINER=	kei@NetBSD.org
COMMENT=	Machine-independent part of TeXfamily (pTeX, JTeX, MuLTeX)

WRKSRC=		${WRKDIR}
DIST_SUBDIR=	TeXfamily
EXTRACT_ONLY=	jis${EXTRACT_SUFX} nmin-ngoth${EXTRACT_SUFX} \
		standard${EXTRACT_SUFX} morisawa${EXTRACT_SUFX}
NO_CONFIGURE=	yes
NO_BUILD=	yes
NO_MTREE=	yes
PLIST_SRC=	${WRKDIR}/PLIST_SRC
TEX_ACCEPTED=	teTeX1 # teTeX2 teTeX3

do-install:
	@${INSTALL_DATA_DIR} ${PREFIX}/share/texmf.local
.for f in ptex-texmf-2.0 texfam-texmf-latex209 texfam-texmf-j1.9 \
    texfam-texmf-j1.9.1 texfam-texmf-m0.8 \
    mulfonts-vf mulfonts-subtfm jis nmin-ngoth standard morisawa
	@cd ${PREFIX}/share/texmf.local; \
		${PAX} -O -rz -pe -s /ls-R// \
			-f ${DISTDIR}/${DIST_SUBDIR}/${f}${EXTRACT_SUFX}
.endfor
	@${INSTALL_DATA_DIR} ${PREFIX}/share/texmf.local/doc/fonts
	@cd ${WRKDIR}/morisawa/tfm/ptex; \
		${PAX} -rw -pe . ${PREFIX}/share/texmf.local/fonts/tfm/ptex
.for font in jis nmin-ngoth standard morisawa
	@cd ${WRKDIR}/${font}; \
		for d in tfm/dvips vf; do \
			${PAX} -rw -pe $$d ${PREFIX}/share/texmf.local/fonts; \
		done
	@${INSTALL_DATA} ${WRKDIR}/${font}/README.txt \
		${PREFIX}/share/texmf.local/doc/fonts/README.${font}
.endfor

post-install:
	@cd ${PREFIX}; \
	 ${CAT} ${PKGDIR}/PLIST > ${PLIST_SRC}; \
	 ${FIND} share/texmf.local -type f -print |sort >> ${PLIST_SRC}; \
	 for LINK in `${FIND} share/texmf.local -type l -print`; do \
		set - X `${FILE} $$LINK`; \
		${ECHO} "@exec ${LN} -s $$6 %D/$$LINK" >>${PLIST_SRC}; \
		${ECHO} "@unexec ${RM} -f %D/$$LINK" >>${PLIST_SRC}; \
	 done; \
	 for DIR in `${FIND} share/texmf.local -type d -print | sort -r`; do \
	 	if [ -z "`ls $$DIR`" ]; then \
			${ECHO} "@exec ${MKDIR} %D/$$DIR" >>${PLIST_SRC}; \
	 	fi; \
	 	${ECHO} "@dirrm $$DIR" >>${PLIST_SRC}; \
	 done

.include "../../mk/tex.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
