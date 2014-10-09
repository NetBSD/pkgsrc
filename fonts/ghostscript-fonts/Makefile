# $NetBSD: Makefile,v 1.21 2014/10/09 14:06:33 wiz Exp $

DISTNAME=		ghostscript-fonts-8.11
PKGREVISION=		3
CATEGORIES=		fonts
MASTER_SITES+=		${MASTER_SITE_SOURCEFORGE:=ghostscript/} \
			ftp://mirror.cs.wisc.edu/pub/mirrors/ghost/fonts/
DISTFILES=		${GS_FONTS_OTHER}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://gs-fonts.sourceforge.net/
COMMENT=		Postscript fonts for Aladdin Ghostscript

GS_FONTS_OTHER=		ghostscript-fonts-other-6.0.tar.gz

CONFLICTS=		ghostscript-[0-5]* ghostscript-x11-[0-5]*

DIST_SUBDIR=		ghostscript
NO_CONFIGURE=		YES
NO_BUILD=		YES
WRKSRC=			${WRKDIR}/fonts

FONTS_DIR=		${PREFIX}/share/ghostscript/fonts
INSTALLATION_DIRS=	share/ghostscript/fonts
REQD_DIRS+=		share/ghostscript

do-install:
	for ext in afm gsf pfa pfm;				\
	do							\
		for f in ${WRKSRC}/*.$${ext};			\
		do						\
			${INSTALL_DATA} $${f} ${DESTDIR}${FONTS_DIR};	\
		done;						\
	done

.include "../../mk/bsd.pkg.mk"
