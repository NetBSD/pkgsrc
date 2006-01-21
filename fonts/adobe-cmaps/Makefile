# $NetBSD: Makefile,v 1.15 2006/01/21 14:37:35 jlam Exp $

DISTNAME=	adobe-cmaps-20051109
CATEGORIES=	fonts print
MASTER_SITES=	# empty

CMAP_FILES=	ac15 ag14 ai0 aj16 aj20 ak12
RKSJ_FILES=	rksj-cmaps
CMAP_DISTFILES=	${CMAP_FILES:S/$/.tar.Z/} ${RKSJ_FILES:S/$/.tar.Z/}
.for FILE in ${CMAP_DISTFILES}
SITES_${FILE}+=	ftp://ftp.oreilly.com/pub/examples/nutshell/cjkv/adobe/
.endfor
DISTFILES+=	${CMAP_DISTFILES}
EXTRACT_ONLY=	${CMAP_DISTFILES}

PDFCORE=	chinese_s chinese_t japanese korean
PDFCORE_DISTFILES=	${PDFCORE:S/$/.zip/}
.for FILE in ${PDFCORE_DISTFILES}
SITES_${FILE}+=	http://partners.adobe.com/public/developer/en/pdf/
.endfor
DISTFILES+=	${PDFCORE_DISTFILES}

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://partners.adobe.com/public/developer/opentype/
COMMENT=	Adobe CMap files for CJK

DIST_SUBDIR=	${PKGNAME_NOREV}
NO_CONFIGURE=	yes
NO_BUILD=	yes
USE_TOOLS+=	unzip

RESOURCEDIR=	${PREFIX}/share/Adobe/Resource

do-install:
	${INSTALL_DATA_DIR} ${RESOURCEDIR}
	for file in ${CMAP_DISTFILES}; do				\
		extract_file="${_DISTDIR}/$${file}"; export extract_file; \
		cd ${RESOURCEDIR}; ${EXTRACT_CMD};			\
	done
	for file in ${PDFCORE}; do					\
		${MKDIR} ${RESOURCEDIR}/pdfcorefonts/$${file};		\
		cd ${RESOURCEDIR}/pdfcorefonts/$${file};		\
		unzip -aaoq ${_DISTDIR}/$${file}.zip;			\
	done
	${INSTALL_DATA_DIR} ${RESOURCEDIR}/CMap
	cd ${RESOURCEDIR}; for dir in ${CMAP_FILES}; do			\
		for file in $${dir}/CMap/*; do				\
			${LN} -sf ../$${file} ${RESOURCEDIR}/CMap;	\
		done;							\
	done
	cd ${RESOURCEDIR}; for dir in ${RKSJ_FILES}; do			\
		for file in $${dir}/*; do				\
			${LN} -sf ../$${file} ${RESOURCEDIR}/CMap;	\
		done;							\
	done
	cd ${RESOURCEDIR}; for dir in ${PDFCORE}; do			\
		for file in pdfcorefonts/$${dir}/*; do			\
			case $${file} in				\
			*.pdf)	;;					\
			*)						\
				${RM} -f ${RESOURCEDIR}/CMap/`${BASENAME} $${file}`; \
				${LN} -sf ../$${file} ${RESOURCEDIR}/CMap; \
				;;					\
			esac;						\
		done;							\
	done

.include "../../mk/bsd.pkg.mk"
