# $NetBSD: Makefile,v 1.11 2016/01/29 10:02:52 jperkin Exp $

DISTNAME=	install-sh-20100824
CATEGORIES=	sysutils
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Install script compatible with the BSD install program
LICENSE=	mit

BOOTSTRAP_PKG=	yes
USE_TOOLS+=	sed
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
	${INSTALL_SCRIPT_DIR} ${DESTDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/install-sh ${DESTDIR}${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
