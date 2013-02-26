# $NetBSD: Makefile,v 1.12 2013/02/26 11:07:06 joerg Exp $
#

DISTNAME=	figlet-fonts-20021023
PKGREVISION=	1
CATEGORIES=	misc
MASTER_SITES=	ftp://ftp.figlet.org/pub/figlet/fonts/
DISTFILES=	contributed.tar.gz international.tar.gz ms-dos.tar.gz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.figlet.org/
COMMENT=	Additional fonts for figlet

DEPENDS+=	figlet-[0-9]*:../../misc/figlet

DIST_SUBDIR=	${DISTNAME}
NO_CONFIGURE=	yes
NO_BUILD=	yes

USE_TOOLS+=		tar gzcat
INSTALLATION_DIRS=	bin share/figlet

post-extract:
	cd ${WRKDIR}/international && \
		${GZCAT} cjkfonts.tar.gz | ${TAR} -xf - && \
		${RM} -f cjkfonts.tar.gz
# conflicts with font of same name in figlet
	${MV} ${WRKDIR}/contributed/banner.flf ${WRKDIR}/contributed/banner1.flf

do-install:
	cd ${WRKDIR}/contributed && \
		${INSTALL_DATA} *.fl* *.txt ${DESTDIR}${PREFIX}/share/figlet
	cd ${WRKDIR}/contributed/bdffonts && \
		${INSTALL_DATA} *.* ${DESTDIR}${PREFIX}/share/figlet
	cd ${WRKDIR}/contributed/C64-fonts && \
		${INSTALL_DATA} *.* ${DESTDIR}${PREFIX}/share/figlet
	cd ${WRKDIR}/international && \
		${INSTALL_DATA} *.* ${DESTDIR}${PREFIX}/share/figlet
	${INSTALL_SCRIPT} ${WRKDIR}/international/febrew \
		${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKDIR}/ms-dos/dosrebel.flf \
		${DESTDIR}${PREFIX}/share/figlet

.include "../../mk/bsd.pkg.mk"
