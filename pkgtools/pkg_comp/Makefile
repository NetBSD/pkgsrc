# $NetBSD: Makefile,v 1.29 2005/06/06 18:50:07 jmmv Exp $

DISTNAME=	pkg_comp-1.21
CATEGORIES=	pkgtools
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	jmmv@NetBSD.org
COMMENT=	Build packages inside a chroot jail

PKG_INSTALLATION_TYPES=	overwrite pkgviews
ONLY_FOR_PLATFORM=	NetBSD-*-*

WRKSRC=		${WRKDIR}
EXTRACT_ONLY=	# empty
NO_CHECKSUM=	YES
NO_CONFIGURE=	YES
NO_BUILD=	YES

INSTALLATION_DIRS=	man/man8 sbin

do-install:
	${INSTALL_SCRIPT} ${FILESDIR}/pkg_comp.sh ${PREFIX}/sbin/pkg_comp
	${INSTALL_MAN} ${FILESDIR}/pkg_comp.8 ${PREFIX}/man/man8/pkg_comp.8

.include "../../mk/bsd.pkg.mk"
