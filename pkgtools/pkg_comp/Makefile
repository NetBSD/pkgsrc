# $NetBSD: Makefile,v 1.1.1.1 2002/09/07 00:08:35 rh Exp $

DISTNAME=	pkg_comp-1.0
CATEGORIES=	pkgtools
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	jmmv@hispabsd.org
COMMENT=	Build packages inside a chroot jail

EXTRACT_ONLY=	# empty
NO_CHECKSUM=	YES
NO_PATCH=	YES
NO_CONFIGURE=	YES
NO_BUILD=	YES
WRKSRC=		${WRKDIR}

.include "../../mk/bsd.prefs.mk"

do-install:
	${INSTALL_SCRIPT} ${FILESDIR}/pkg_comp.sh ${PREFIX}/sbin/pkg_comp
	${INSTALL_MAN} ${FILESDIR}/pkg_comp.8 ${PREFIX}/man/man8/pkg_comp.8

.include "../../mk/bsd.pkg.mk"
