# $NetBSD: Makefile,v 1.46 2010/07/20 16:50:25 jmmv Exp $

DISTNAME=	pkg_comp-1.34
CATEGORIES=	pkgtools
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	jmmv@NetBSD.org
COMMENT=	Build packages inside a chroot jail

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

ONLY_FOR_PLATFORM=	NetBSD-*-*

WRKSRC=		${WRKDIR}
NO_CONFIGURE=	YES
NO_BUILD=	YES

INSTALLATION_DIRS=	${PKGMANDIR}/man8 sbin

do-install:
	${INSTALL_SCRIPT} ${FILESDIR}/pkg_comp.sh ${DESTDIR}${PREFIX}/sbin/pkg_comp
	${INSTALL_MAN} ${FILESDIR}/pkg_comp.8 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man8/pkg_comp.8

.include "../../mk/bsd.pkg.mk"
