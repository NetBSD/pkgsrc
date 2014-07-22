# $NetBSD: Makefile,v 1.1 2014/07/22 08:09:16 manu Exp $

DISTNAME=	sysvinit-2.88dsf
PKGNAME=	${DISTNAME:S/sysvinit/pidof/}
CATEGORIES=	sysutils
MASTER_SITES=	http://download.savannah.gnu.org/releases/sysvinit/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://download.savannah.gnu.org/releases/sysvinit/
COMMENT=	Linux pidof(8) command
LICENSE=	gnu-gpl-v2

USE_TOOLS+=	gmake
BUILD_DIRS=	src
BUILD_TARGET=	killall5
AUTO_MKDIRS=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/killall5	\
	    ${DESTDIR}${PREFIX}/sbin/pidof
	${INSTALL_MAN} ${WRKSRC}/man/pidof.8		\
	    ${DESTDIR}${PREFIX}/${PKGMANDIR}/man8

# url2pkg-marker (please do not remove this line.)
.include "../../mk/bsd.pkg.mk"
