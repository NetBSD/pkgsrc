# $NetBSD: Makefile,v 1.1.1.1 2000/10/29 08:04:56 itojun Exp $
#

DISTNAME=	ksc5601fonts-20000904
CATEGORIES=	fonts x11 korean
DISTFILES=	${BAEKMUK} ${MIZI} ${HANYANG} ${PINETREE}

MAINTAINER=	packages@netbsd.org

USE_X11BASE=	yes
EXTRACT_ONLY=	# empty

MAKE_ENV+=	FONTDIR=${FONTDIR} GZIP_CMD="${GZIP_CMD}"

# fonts
MASTER_SITES+=	ftp://ftp.mizi.com/pub/baekmuk/ \
		http://zinc.skku.ac.kr/~wkpark/baekmuk/
BAEKMUK=	baekmuk-2.0.tar.gz
EXTRACT_ONLY+=	baekmuk-2.0.tar.gz
BAEKMUK_BDF=	batang10.bdf batang10b.bdf batang12.bdf batang12b.bdf \
		batang14.bdf batang14b.bdf batang16.bdf batang16b.bdf \
		batang18.bdf batang18b.bdf batang20.bdf batang20b.bdf \
		batang24.bdf batang24b.bdf dotum10.bdf dotum12.bdf dotum14.bdf \
		dotum16.bdf dotum18.bdf dotum20.bdf dotum24.bdf gulim10.bdf \
		gulim10b.bdf gulim12.bdf gulim12b.bdf gulim14.bdf gulim14b.bdf \
		gulim16.bdf gulim16b.bdf gulim18.bdf gulim18b.bdf gulim20.bdf \
		gulim20b.bdf gulim24.bdf gulim24b.bdf hline10.bdf hline12.bdf \
		hline14.bdf hline16.bdf hline18.bdf hline20.bdf hline24.bdf

MASTER_SITES+=	ftp://ftp.mizi.co.kr/pub/hanIM/
MIZI=		xfntmizi-1.1-2.noarch.rpm
MIZI_PCF=	mzgt16e.pcf mzgt16h1.pcf mzmj16h.pcf mzpg16h.pcf mzsm16h.pcf \
		mzgt16h.pcf mzmj16e.pcf mzpg16e.pcf mzsm16e.pcf

MASTER_SITES+=	ftp://ftp.kaist.ac.kr/pub/hangul/fonts/ \
		ftp://ftp.kreonet.re.kr/pub/hangul/cair-archive/fonts/
HANYANG=	hanyang-font-pcf.tar.gz
EXTRACT_ONLY+=	hanyang-font-pcf.tar.gz
HANYANG_PCF=	hgm10.pcf hgm12.pcf hgm14.pcf hgm16.pcf hgm18.pcf hgm20.pcf \
		hmm10.pcf hmm12.pcf hmm14.pcf hmm16.pcf hmm18.pcf hmm20.pcf

# quality is low - i'd rather not install it
#MASTER_SITES+=	ftp://cglab.snu.ac.kr/pub/hangul/n3f/tar/ \
#		ftp://ftp.kaist.ac.kr/pub/hangul/fonts/ \
#		ftp://ftp.kreonet.re.kr/pub/hangul/cair-archive/fonts/
#PINETREE=	pinetree.precomposed-1.01-bdf.tar.gz
#EXTRACT_ONLY+=	pinetree.precomposed-1.01-bdf.tar.gz

.if defined(MIZI)
BUILD_DEPENDS+=	rpm2cpio:../../misc/rpm
.endif

FONTDIR=${PREFIX}/lib/X11/fonts/local

post-extract:
	${MKDIR} ${WRKSRC}
	${CP} ${FILESDIR}/Makefile ${WRKSRC}
	(cd ${WRKSRC}; ${MAKE} prepare)

post-patch:
.if defined(BAEKMUK)
	for i in ${BAEKMUK_BDF}; do \
		${MV} ${WRKDIR}/$$i ${WRKDIR}/$$i.dist; \
		${SED} -e 's/ksx1001.1997/ksc5601.1987/g' <${WRKDIR}/$$i.dist \
		    >${WRKDIR}/$$i; \
	done
.endif

post-build:
.if defined(MIZI)
	(cd ${WRKSRC}; rpm2cpio ${_DISTDIR}/${MIZI} | \
	    cpio -i --make-directories *.pcf.Z)
	(cd ${WRKSRC}; for i in ${MIZI_PCF}; do \
		${GUNZIP_CMD} -c usr/lib/X11/fonts/misc/$$i.Z > $$i; \
	done)
.endif
.if defined(HANYANG)
	for i in ${HANYANG_PCF}; do \
		${MV} ${WRKDIR}/$$i ${WRKSRC}; \
	done
.endif

pre-install:
	[ -d ${FONTDIR} ] || ${MKDIR} ${FONTDIR}

post-install:
	(cd ${FONTDIR}; mkfontdir)

.include "../../mk/bsd.pkg.mk"
