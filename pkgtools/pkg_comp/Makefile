# $NetBSD: Makefile,v 1.9 2003/03/29 12:42:10 jmmv Exp $

DISTNAME=	pkg_comp-1.6
WRKSRC=		${WRKDIR}
CATEGORIES=	pkgtools
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	jmmv@netbsd.org
COMMENT=	Build packages inside a chroot jail

EXTRACT_ONLY=	# empty
NO_CHECKSUM=	YES
NO_CONFIGURE=	YES
NO_BUILD=	YES

.include "../../mk/bsd.prefs.mk"

do-install:
	${INSTALL_SCRIPT} ${FILESDIR}/pkg_comp.sh ${PREFIX}/sbin/pkg_comp
	${INSTALL_MAN} ${FILESDIR}/pkg_comp.8 ${PREFIX}/man/man8/pkg_comp.8

.include "../../mk/bsd.pkg.mk"
