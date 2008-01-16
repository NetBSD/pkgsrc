# $NetBSD: Makefile,v 1.8 2008/01/16 03:32:59 tnn Exp $

DISTNAME=		posix_headers-0.5
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
PKG_DESTDIR_SUPPORT=	user-destdir

PLIST_SRC=		${WRKDIR}/PLIST_SRC
REPLACE_SH+=		make.sh
BUILDING_POSIX_HEADERS=	yes

do-extract:
	cp -R ${FILESDIR} ${WRKSRC}

do-build:
	cd ${WRKSRC} && ./make.sh
	find ${WRKSRC} -name "*.h" | sed 's,${WRKSRC}/,,' > ${WRKSRC}/hfiles
	cat ${WRKSRC}/hfiles | sed 's,^,include/,' > ${PLIST_SRC}

do-install:
	for f in `cat ${WRKSRC}/hfiles`; do \
	${INSTALL_DATA} ${WRKSRC}/$$f ${DESTDIR}${PREFIX}/include/$$f; done

.include "../../mk/bsd.pkg.mk"
