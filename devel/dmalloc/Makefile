# $NetBSD: Makefile,v 1.20 2009/12/09 20:35:53 joerg Exp $

DISTNAME=		dmalloc-5.4.2
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=dmalloc/}
EXTRACT_SUFX=		.tgz

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://dmalloc.com/
COMMENT=		Run-time configurable debugging malloc library

PKG_DESTDIR_SUPPORT=	user-destdir

MAKE_JOBS_SAFE=		no

USE_LANGUAGES=		c c++
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-shlib
CFLAGS+=		-fPIC -DPIC
CONFIGURE_ARGS+=	--enable-threads
INFO_FILES=		# PLIST

INSTALLATION_DIRS=	${PKGINFODIR}

INSTALL_MAKE_FLAGS+=	prefix=${DESTDIR}${PREFIX}

# XXX the "installinfo" target is broken
#INSTALL_TARGET=	install installinfo
post-install:
	cd ${WRKSRC}/docs; for f in *.info *.info-[0-9]*; do		\
		${TEST} ! -f "$$f" ||					\
		${INSTALL_DATA} "$$f" ${DESTDIR}${PREFIX}/${PKGINFODIR}; \
	done

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
