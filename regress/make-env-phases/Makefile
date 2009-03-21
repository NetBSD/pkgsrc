# $NetBSD: Makefile,v 1.3 2009/03/21 05:43:53 darcy Exp $
#

DISTNAME=	make-env-phases-1.0
CATEGORIES=	regress
MASTER_SITES=	# none
DISTFILES=	# none

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Tests whether MAKE_ENV changes between build and install phase

NO_CHECKSUM=	yes
NO_CONFIGURE=	yes
NO_PACKAGE=	yes
WRKSRC=		${WRKDIR}

do-build:
	@cd ${WRKDIR} && \
		echo "${MAKE_ENV}" >build-make-env.txt

do-install:
	@cd ${WRKDIR} && \
		echo "${MAKE_ENV}" >install-make-env.txt && \
                ${CMP} build-make-env.txt install-make-env.txt >/dev/null && \
                echo "The variable MAKE_ENV remains unchanged."

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
