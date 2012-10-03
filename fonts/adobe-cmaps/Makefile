# $NetBSD: Makefile,v 1.21 2012/10/03 18:28:16 asau Exp $

DISTNAME=	adobe-cmaps-20060615
CATEGORIES=	fonts print
MASTER_SITES=	# empty

CMAP_FILES=	ac15 ag15 ai0 aj16 aj20 ak12
RKSJ_FILES=	rksj-cmaps
CMAP_DISTFILES=	${CMAP_FILES:S/$/.tar.Z/} ${RKSJ_FILES:S/$/.tar.Z/}
.for f in ${CMAP_DISTFILES}
SITES.${f}+=	ftp://ftp.oreilly.com/pub/examples/nutshell/cjkv/adobe/
.endfor
DISTFILES+=	${CMAP_DISTFILES}
EXTRACT_ONLY=	${CMAP_DISTFILES}

PDFCORE=	chinese_s chinese_t japanese korean
PDFCORE_DISTFILES=	${PDFCORE:S/$/.zip/}
.for f in ${PDFCORE_DISTFILES}
SITES.${f}+=	http://partners.adobe.com/public/developer/en/pdf/
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
	${INSTALL_DATA_DIR} ${DESTDIR}${RESOURCEDIR}
	set -e; \
	for file in ${CMAP_DISTFILES}; do				\
		extract_file="${_DISTDIR}/$${file}"; export extract_file; \
		cd ${DESTDIR}${RESOURCEDIR}; ${EXTRACT_CMD};		\
	done
	set -e; \
	for file in ${PDFCORE}; do					\
		${MKDIR} ${DESTDIR}${RESOURCEDIR}/pdfcorefonts/$${file}; \
		cd ${DESTDIR}${RESOURCEDIR}/pdfcorefonts/$${file};	\
		${UNZIP_CMD} -aaoq ${_DISTDIR}/$${file}.zip;		\
	done
	${INSTALL_DATA_DIR} ${DESTDIR}${RESOURCEDIR}/CMap
	set -e; \
	cd ${DESTDIR}${RESOURCEDIR}; for dir in ${CMAP_FILES}; do	\
		for file in $${dir}/CMap/*; do				\
			${LN} -sf ../$${file} ${DESTDIR}${RESOURCEDIR}/CMap; \
		done;							\
	done
	set -e; \
	cd ${DESTDIR}${RESOURCEDIR}; for dir in ${RKSJ_FILES}; do	\
		for file in $${dir}/*; do				\
			${LN} -sf ../$${file} ${DESTDIR}${RESOURCEDIR}/CMap; \
		done;							\
	done
	set -e; \
	cd ${DESTDIR}${RESOURCEDIR}; for dir in ${PDFCORE}; do		\
		for file in pdfcorefonts/$${dir}/*; do			\
			case $${file} in				\
			*.pdf)	;;					\
			*)						\
				${RM} -f ${DESTDIR}${RESOURCEDIR}/CMap/`${BASENAME} $${file}`; \
				${LN} -sf ../$${file} ${DESTDIR}${RESOURCEDIR}/CMap; \
				;;					\
			esac;						\
		done;							\
	done

.include "../../mk/bsd.pkg.mk"
