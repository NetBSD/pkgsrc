# $NetBSD: Makefile,v 1.1.1.1 2004/12/25 19:32:51 wiz Exp $
#

DISTNAME=	figlet-fonts-20021023
CATEGORIES=	misc
MASTER_SITES=	ftp://ftp.figlet.org/pub/figlet/fonts/
DISTFILES=	contributed.tar.gz international.tar.gz ms-dos.tar.gz

MAINTAINER=     tech-pkg@NetBSD.org
HOMEPAGE=	http://www.figlet.org/
COMMENT=	Additional fonts for figlet

DEPENDS+=	figlet-[0-9]*:../../misc/figlet

DIST_SUBDIR=	${DISTNAME}
NO_CONFIGURE=	# defined
NO_BUILD=	# defined

post-extract:
	cd ${WRKDIR}/international && \
		${GZIP_CMD} -cd cjkfonts.tar.gz | ${GTAR} -xf - && \
		${RM} -f cjkfonts.tar.gz
# conflicts with font of same name in figlet
	${MV} ${WRKDIR}/contributed/banner.flf ${WRKDIR}/contributed/banner1.flf

do-install:
	cd ${WRKDIR}/contributed && \
		${INSTALL_DATA} *.fl* *.txt ${PREFIX}/share/figlet
	cd ${WRKDIR}/contributed/bdffonts && \
		${INSTALL_DATA} *.* ${PREFIX}/share/figlet
	cd ${WRKDIR}/contributed/C64-fonts && \
		${INSTALL_DATA} *.* ${PREFIX}/share/figlet
	cd ${WRKDIR}/international && \
		${INSTALL_DATA} *.* ${PREFIX}/share/figlet
	${INSTALL_SCRIPT} ${WRKDIR}/international/febrew ${PREFIX}/bin
	${INSTALL_DATA} ${WRKDIR}/ms-dos/dosrebel.flf ${PREFIX}/share/figlet

.include "../../mk/bsd.pkg.mk"
