# $NetBSD: Makefile,v 1.18 2006/10/04 21:35:58 wiz Exp $

DISTNAME=		dmalloc-5.4.2
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=dmalloc/}
EXTRACT_SUFX=		.tgz

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://dmalloc.com/
COMMENT=		Run-time configurable debugging malloc library

USE_LANGUAGES=		c c++
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-shlib
CFLAGS+=		-fPIC -DPIC
CONFIGURE_ARGS+=	--enable-threads
INFO_FILES=		# PLIST

INSTALLATION_DIRS=	${PKGINFODIR}

# XXX the "installinfo" target is broken
#INSTALL_TARGET=	install installinfo
post-install:
	cd ${WRKSRC}/docs; for f in *.info *.info-[0-9]*; do		\
		${TEST} ! -f "$$f" ||					\
		${INSTALL_DATA} "$$f" ${PREFIX}/${PKGINFODIR};		\
	done

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
