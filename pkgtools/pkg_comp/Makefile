# $NetBSD: Makefile,v 1.54 2015/08/17 08:18:31 wiz Exp $

PKGNAME=	pkg_comp-1.38
CATEGORIES=	pkgtools

MAINTAINER=	jmmv@NetBSD.org
COMMENT=	Build packages inside a chroot jail
LICENSE=	modified-bsd

ONLY_FOR_PLATFORM=	NetBSD-*-*

WRKSRC=		${WRKDIR}
NO_CONFIGURE=	YES
NO_BUILD=	YES

INSTALLATION_DIRS=	${PKGMANDIR}/man8 sbin

do-install:
	${INSTALL_SCRIPT} ${FILESDIR}/pkg_comp.sh ${DESTDIR}${PREFIX}/sbin/pkg_comp
	${INSTALL_MAN} ${FILESDIR}/pkg_comp.8 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man8/pkg_comp.8

.include "../../mk/bsd.pkg.mk"
