# $NetBSD: Makefile,v 1.3 2002/12/14 23:27:50 jmmv Exp $

DISTNAME=	pkg_comp-1.2
CATEGORIES=	pkgtools
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	jmmv@netbsd.org
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
