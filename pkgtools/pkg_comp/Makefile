# $NetBSD: Makefile,v 1.16 2003/12/19 09:51:55 jmmv Exp $

DISTNAME=	pkg_comp-1.12
WRKSRC=		${WRKDIR}
CATEGORIES=	pkgtools
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	jmmv@NetBSD.org
COMMENT=	Build packages inside a chroot jail

EXTRACT_ONLY=	# empty
NO_CHECKSUM=	YES
NO_CONFIGURE=	YES
NO_BUILD=	YES

do-install:
	${INSTALL_SCRIPT} ${FILESDIR}/pkg_comp.sh ${PREFIX}/sbin/pkg_comp
	${INSTALL_MAN} ${FILESDIR}/pkg_comp.8 ${PREFIX}/man/man8/pkg_comp.8

.include "../../mk/bsd.pkg.mk"
