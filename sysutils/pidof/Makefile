# $NetBSD: Makefile,v 1.4 2020/01/18 23:35:20 rillig Exp $

DISTNAME=	sysvinit-2.96
PKGNAME=	${DISTNAME:S/sysvinit/pidof/}
CATEGORIES=	sysutils
MASTER_SITES=	http://download.savannah.gnu.org/releases/sysvinit/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://download.savannah.gnu.org/releases/sysvinit/
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

.include "../../mk/bsd.pkg.mk"
