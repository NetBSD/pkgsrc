# $NetBSD: Makefile,v 1.1 2018/11/09 06:46:03 rillig Exp $
#

DISTNAME=	env-vars-1.0
CATEGORIES=	regress
MASTER_SITES=	# none
DISTFILES=	# none

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Demonstrates the various *_ENV variables
LICENSE=	2-clause-bsd

USE_TOOLS+=	printf env sed sort
NO_CHECKSUM=	yes
HAS_CONFIGURE=	yes
WRKSRC=		${WRKDIR}

ENV_VARS+=	PKGSRC_MAKE_ENV
ENV_VARS+=	EXTRACT_ENV
ENV_VARS+=	CONFIGURE_ENV
ENV_VARS+=	ALL_ENV
ENV_VARS+=	MAKE_ENV
ENV_VARS+=	BSD_MAKE_ENV
ENV_VARS+=	INSTALL_ENV

.for v in ${ENV_VARS}
${v}+=			${v}_set=yes
.endfor

do-extract:
	${CP} ${FILESDIR}/configure ${FILESDIR}/Makefile ${WRKSRC}

.include "../../mk/bsd.pkg.mk"

# These definitions must be below bsd.pkg.mk, or their pkgsrc default
# actions will not be run.
#
pre-fetch	do-fetch	post-fetch \
pre-extract	do-extract	post-extract \
pre-patch	do-patch	post-patch \
pre-configure	do-configure	post-configure \
pre-build	do-build	post-build \
pre-install	do-install	post-install: \
save-env-vars

save-env-vars: .USE .PHONY
	${RUN}								\
	env | sed -n -e '/^[^=]*_set=yes$$/p' | LC_ALL=C sort		\
	> "$$REGRESS_TMPDIR/${.TARGET}.vars"
