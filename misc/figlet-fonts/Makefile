# $NetBSD: Makefile,v 1.4 2005/06/17 03:50:21 jlam Exp $
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

PKGSRC_USE_TOOLS+=	gtar gzcat
INSTALLATION_DIRS=	bin share/figlet

post-extract:
	cd ${WRKDIR}/international && \
		${GZCAT} cjkfonts.tar.gz | ${GTAR} -xf - && \
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
