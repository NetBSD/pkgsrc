# $NetBSD: Makefile,v 1.2 2011/10/13 16:01:06 gson Exp $
#

DISTNAME=	mkmemstick-20111013
CATEGORIES=	sysutils
MASTER_SITES=	# none
DISTFILES=	# none

MAINTAINER=	agc@NetBSD.org
HOMEPAGE=	http://genericzero.wordpress.com/2009/08/01/install-netbsd-from-a-usb-memory-stick-the-easy-way/
COMMENT=	Create a memory stick image from NetBSD Installation CDs

DEPENDS+=	cdrtools-[0-9]*:../../sysutils/cdrtools

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}
USE_LANGUAGES=	# none
AUTO_MKDIRS=	yes

do-configure:
	cp ${FILESDIR}/mkmemstick.sh ${WRKSRC}/mkmemstick

do-build:

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/mkmemstick ${DESTDIR}${PREFIX}/sbin/mkmemstick


.include "../../mk/bsd.pkg.mk"
