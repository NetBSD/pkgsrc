# $NetBSD: Makefile,v 1.1.1.1 2002/12/27 02:43:47 uebayasi Exp $

DISTNAME=       #
PKGNAME=	dict-data-1.8.0
CATEGORIES=	textproc
MASTER_SITES=	ftp://ftp.dict.org/pub/dict/
#MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=/dict}
DISTFILES=	dict-gazetteer-1.3.tar.gz \
		dict-misc-1.5.tar.gz \
		dict-web1913-1.4.tar.gz \
		web1913-0.46-a.tar.gz \
		dict-wn-1.5.tar.gz

MAINTAINER=	mike@ethmoid.org
HOMEPAGE=	http://www.dict.org/
COMMENT=	Dictionary data for DICTD

DEPENDS=	dict-server>=1.8.0nb1:../../textproc/dict-server

USE_GMAKE=	# defined

# Strip '.gz', strip '.tar'.
DICTIONARIES=	${DISTFILES:R:R}

LEXICONS=	easton.dict.dz \
		easton.index \
		elements.dict.dz \
		elements.index \
		foldoc.dict.dz \
		foldoc.index \
		hitchcock.dict.dz \
		hitchcock.index \
		jargon.dict.dz \
		jargon.index \
		world95.dict.dz \
		world95.index
GAZETTEER=	gazetteer.dict.dz \
		gazetteer.index
WEB1913=	web1913.dict.dz \
		web1913.index
WN=		wn.dict.dz \
		wn.index

do-configure:
	@for d in ${DICTIONARIES}; do \
		(cd ${WRKDIR}/$${d}; [ -f configure ] && ${SH} configure); \
	done

# Build dictinaries
do-build:
	@cd ${WRKDIR}/dict-web1913-1.4; ${MAKE_PROGRAM}		# For libmaa
	@${LN} -fs ${WRKDIR}/web1913-0.46-a ${WRKDIR}/dict-web1913-1.4/web1913
	@for d in ${DICTIONARIES}; do \
		(cd ${WRKDIR}/$$d; \
		    ${MAKE_PROGRAM} db); \
	done
	${FIND} ${WRKDIR} -name '*.dict' | \
	while read f; do \
		if [ ! -f $${f}.dz ]; then \
			${LOCALBASE}/bin/dictzip $$f; \
		fi; \
	done

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/dictd
	for f in ${LEXICONS}; do \
		${INSTALL_DATA} ${WRKDIR}/dict-misc-1.5/$$f \
		    ${PREFIX}/share/dictd; \
	done
	for f in ${GAZETTEER}; do \
		${INSTALL_DATA} ${WRKDIR}/dict-gazetteer-1.3/$$f \
		    ${PREFIX}/share/dictd; \
	done
	for f in ${WEB1913}; do \
		${INSTALL_DATA} ${WRKDIR}/dict-web1913-1.4/$$f \
		    ${PREFIX}/share/dictd; \
	done
	for f in ${WN}; do \
		${INSTALL_DATA} ${WRKDIR}/dict-wn-1.5/$$f \
		    ${PREFIX}/share/dictd; \
	done

.include "../../mk/bsd.pkg.mk"
