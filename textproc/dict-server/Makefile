# $NetBSD: Makefile,v 1.6 2002/11/11 12:36:40 uebayasi Exp $

DISTNAME=       dictd-1.8.0
PKGNAME=	dict-server-1.8.0
CATEGORIES=	textproc
MASTER_SITES=	ftp://ftp.dict.org/pub/dict/
#MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=/dict}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		dict-gazetteer-1.3.tar.gz \
		dict-misc-1.5.tar.gz \
		dict-web1913-1.4.tar.gz \
		web1913-0.46-a.tar.gz \
		dict-wn-1.5.tar.gz

MAINTAINER=	mike@ethmoid.org
HOMEPAGE=	http://www.dict.org/
COMMENT=	Dictionary Service Protocol server

USE_BUILDLINK2=	# defined
USE_GMAKE=	# defined
GNU_CONFIGURE=	# defined
CONFIGURE_ARGS+=--with-etcdir=${PREFIX}/etc

ALL_TARGET=	dictd dictzip
INSTALL_TARGET=	install.dictd install.dictzip install.dictfmt

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

post-extract:
	${RM} -fr ${WRKDIR}/dict-web1913-1.4/libmaa
	${LN} -fs ${WRKDIR}/dictd-1.8.0/libmaa ${WRKDIR}/dict-web1913-1.4/libmaa

# A symbol T_USER is defined in trap.h so...
post-patch:
	${GREP} -lr T_USER ${WRKSRC} | \
	while read f; do \
		${MV} $$f $${f}.orig; \
		${SED} \
		    -e 's/T_USER/T_XUSER/g' \
		    -e 's/DICT_XUSER/DICT_USER/g' \
		    $${f}.orig >$$f; \
	done

# Build dictinaries
post-build:
	@${LN} -fs ${WRKDIR}/web1913-0.46-a ${WRKDIR}/dict-web1913-1.4/web1913
	@for d in dict-misc-1.5 dict-gazetteer-1.3 dict-web1913-1.4 dict-wn-1.5; do \
		(cd ${WRKDIR}/$$d; \
		    ${SH} configure; \
		    ${MAKE_PROGRAM} db; \
		); \
	done
	${FIND} ${WRKDIR} -name '*.dict' | \
	while read f; do \
		if [ ! -f $${f}.dz ]; then \
			${WRKSRC}/dictzip $$f; \
		fi; \
	done

post-install:
	${SED} "s#/usr/lib/dict#${PREFIX}/share/dictd#" \
		${WRKSRC}/dictd.conf >${PREFIX}/etc/dictd.conf
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

.include "../../devel/libtool/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
