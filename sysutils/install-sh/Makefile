# $NetBSD: Makefile,v 1.1.1.1 2006/07/17 14:19:01 jlam Exp $

DISTNAME=	install-sh-20060714
CATEGORIES=	sysutils
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	install script compatible with the BSD install program

USE_TOOLS+=	sed
NO_CHECKSUM=	yes
NO_MTREE=	yes
NO_BUILD=	yes

# Use the install script to perform installation to avoid bootstrapping
# issues.
#
INSTALL_SCRIPT=		\
	${SH} ${WRKSRC}/install-sh -c -o ${BINOWN} -g ${BINGRP} -m ${BINMODE}
INSTALL_SCRIPT_DIR=	\
	${SH} ${WRKSRC}/install-sh -d -o ${BINOWN} -g ${BINGRP} -m ${PKGDIRMODE}

do-extract:
	@${CP} -R ${FILESDIR} ${WRKSRC}

do-configure:
	${SED}	-e "s|@DEFAULT_INSTALL_MODE@|"${PKGDIRMODE}"|g"		\
		${WRKSRC}/install-sh.in > ${WRKSRC}/install-sh
do-install:
	${INSTALL_SCRIPT_DIR} ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/install-sh ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
