# $NetBSD: Makefile,v 1.1.1.1 2002/01/12 10:59:30 wiz Exp $
#

DISTNAME=	nvi-1.81.5
CATEGORIES=	editors
MASTER_SITES=	http://www.kotnet.org/~skimo/nvi/devel/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	aymeric@netbsd.org
HOMEPAGE=	http://www.kotnet.org/~skimo/nvi/devel/
COMMENT=	Berkeley nvi with additional features

GNU_CONFIGURE=		YES
CONFIGURE_SCRIPT=	../dist/configure
CONFIGURE_ARGS+=	--with-db3=${BUILDLINK_DIR}
USE_LIBTOOL=		YES
LTCONFIG_OVERRIDE=	${WRKSRC}/../dist/ltconfig

USE_BUILDLINK_ONLY=	YES

WRKSRC=			${WRKDIR}/${DISTNAME}/build.unix

# --program-prefix doesn't work because of a problem with sed
post-install:
	cd ${PREFIX}/bin && \
		${MV} vi nvi && \
		${MV} ex nex && \
		${MV} view nview
	cd ${PREFIX}/man/cat1 && \
		${MV} vi.0 nvi.0 && \
		${MV} ex.0 nex.0 && \
		${MV} view.0 nview.0
	cd ${PREFIX}/man/man1 && \
		${MV} vi.1 nvi.1 && \
		${MV} ex.1 nex.1 && \
		${MV} view.1 nview.1

.include "../../databases/db3/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
