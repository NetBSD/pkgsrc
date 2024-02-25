# $NetBSD: Makefile,v 1.1 2024/02/25 12:09:21 schmonz Exp $

.include "../../mail/vmailmgr/Makefile.common"

PKGNAME=		vmailmgr-base-${VERSION}
CATEGORIES=		mail

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		https://untroubled.org/vmailmgr/
COMMENT=		Virtual domain manager for qmail (base package)
LICENSE=		gnu-gpl-v2

CONFIGURE_ARGS+=	--disable-cgi
CONFIGURE_ARGS+=	--disable-courier-imap
CONFIGURE_ARGS+=	--disable-php
CONFIGURE_ARGS+=	--disable-python

.include "options.mk"

# for vmailmgr.7, without building the heavier docs
# copy-paste-changed from ../../mk/build/build.mk:
post-build:
.for dir in doc
	${RUN}${_ULIMIT_CMD}						\
	cd ${WRKSRC} && cd ${dir} &&					\
	${BUILD_MAKE_CMD} man
.endfor

# copy-paste-changed from ../../mk/install/install.mk:
post-install:
.for dir in doc
	${RUN} ${_ULIMIT_CMD}						\
	cd ${WRKSRC} && cd ${dir} &&					\
	${PKGSRC_SETENV} ${INSTALL_ENV} ${MAKE_ENV} 			\
		${MAKE_PROGRAM} ${MAKE_FLAGS} ${INSTALL_MAKE_FLAGS}	\
			-f ${MAKE_FILE} install-man
.endfor

.include "../../mk/bsd.pkg.mk"
