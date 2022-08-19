# $NetBSD: Makefile,v 1.22 2022/08/19 01:46:09 tnn Exp $

DISTNAME=	artwiz-aleczapka-en-1.3
PKGNAME=	${DISTNAME:S/aleczapka-en/fonts/}
PKGREVISION=	5
CATEGORIES=	fonts
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=artwizaleczapka/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://artwizaleczapka.sourceforge.net/
COMMENT=	Set of free fonts for X11 desktops
LICENSE=	gnu-gpl-v2

NO_BUILD=	yes
NO_CONFIGURE=	yes

FONTS_DIRS.x11=	${PREFIX}/share/fonts/X11/artwiz
REQD_DIRS=	${PREFIX}/share/fonts/X11/artwiz

INSTALLATION_DIRS=	share/fonts/X11/artwiz

do-install:
	for i in ${WRKSRC}/*.pcf; do \
		${INSTALL_DATA} $$i ${DESTDIR}${FONTS_DIRS.x11}; \
	done

.include "../../mk/bsd.pkg.mk"
