# $NetBSD: Makefile,v 1.8 2004/04/24 22:46:10 jlam Exp $

DISTNAME=	adobe-cmaps-20030924
CATEGORIES=	fonts print
MASTER_SITES=	# empty

CMAP_FILES=	ac14 ag14 ai0 aj15 aj20 ak12
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
SITES_${FILE}+=	http://partners.adobe.com/asn/acrobat/download/fontinfo/
.endfor
DISTFILES+=	${PDFCORE_DISTFILES}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://partners.adobe.com/asn/acrobat/technotes.jsp
COMMENT=	Adobe CMap files for CJK

BUILD_DEPENDS+=	unzip-[0-9]*:../../archivers/unzip

DIST_SUBDIR=		${PKGNAME_NOREV}
USE_BUILDLINK2=		# defined
NO_CONFIGURE=		# defined
NO_BUILD=		# defined

RESOURCEDIR=		${PREFIX}/share/Adobe/Resource

do-install:
	${INSTALL_DATA_DIR} ${RESOURCEDIR}
	for file in ${CMAP_DISTFILES}; do				\
		extract_file="${_DISTDIR}/$${file}"; export extract_file; \
		cd ${RESOURCEDIR}; ${EXTRACT_CMD};			\
	done
	for file in ${PDFCORE}; do					\
		${MKDIR} ${RESOURCEDIR}/pdfcorefonts/$${file};		\
		cd ${RESOURCEDIR}/pdfcorefonts/$${file};		\
		${LOCALBASE}/bin/unzip -aaoq ${_DISTDIR}/$${file}.zip;	\
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
