# $NetBSD: Makefile,v 1.2 2007/04/24 23:12:44 tnn Exp $

DISTNAME=		posix_headers-0.4
PKGREVISION=		1
CATEGORIES=		pkgtools
MASTER_SITES=		# empty
DISTFILES=		# empty

MAINTAINER=		tnn@NetBSD.org
HOMEPAGE=		http://www.pkgsrc.org/
COMMENT=		POSIX compatibility headers

NO_PKGTOOLS_REQD_CHECK=	yes
NO_CHECKSUM=		yes
NO_MTREE=		yes
NO_CONFIGURE=		yes
ONLY_FOR_PLATFORM=	HPUX-11.11-* # add more as needed

PLIST_SRC=		${WRKDIR}/PLIST_SRC

POSIX_HEADERS.HPUX=	sys/select.h stdint.h math.h
SUBST_HEADERS.HPUX=	math.h

BUILDING_POSIX_HEADERS=	yes

# Command that uses the C preprocessing feature to find out the real absolute
# path of a header included using #include <someheader.h>
REAL_HEADER_CMD=	${ECHO} "\#include <@REAL_HEADER@>" | ${CC} -E - | \
			${AWK} -F'"' '/\# 1 .*@REAL_HEADER@"/ {print $$2}'

do-extract:
	${MKDIR} ${WRKSRC}
	cd ${FILESDIR} && ${PAX} -rw * ${WRKSRC}

do-build:
.for header in ${SUBST_HEADERS.${OPSYS}}
	realheader=`${REAL_HEADER_CMD:S/@REAL_HEADER@/${header}/}` ;\
	${ECHO} "header: ${header} -> $$realheader" ;\
	${SED} "s|@REAL_HEADER@|$$realheader|" \
	< ${WRKSRC}/${header} > ${WRKSRC}/${header}.tmp
	${MV} ${WRKSRC}/${header}.tmp ${WRKSRC}/${header}
.endfor

do-install:
	for h in ${POSIX_HEADERS.${OPSYS}}; do \
		${INSTALL_DATA} ${WRKSRC}/"$$h" ${PREFIX}/include/"$$h"; \
		${ECHO} include/"$$h" >> ${PLIST_SRC}; \
	done

.include "../../mk/bsd.pkg.mk"
