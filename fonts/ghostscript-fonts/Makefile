# $NetBSD: Makefile,v 1.14 2005/05/30 14:54:00 dillo Exp $

DISTNAME=		ghostscript-fonts-8.11
CATEGORIES=		fonts
MASTER_SITES+=		${MASTER_SITE_SOURCEFORGE:=ghostscript/} \
			ftp://mirror.cs.wisc.edu/pub/mirrors/ghost/fonts/
DISTFILES=		${GS_FONTS_STD} ${GS_FONTS_OTHER}

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://gs-fonts.sourceforge.net/
COMMENT=		Postscript fonts for Aladdin Ghostscript

#  Note: the following two are special files.  In the 5.50 directory
#  on the FTP site, there are symlinks:
#	ghostscript-fonts-other-5.50.tar.gz ->
#		../fonts/ghostscript-fonts-other-4.40.tar.gz
#  To avoid unnecessarily downloading distfiles, do not change these
#  when upgrading the port unless the symlinks/files really change.
#
GS_FONTS_STD=		ghostscript-fonts-std-8.11.tar.gz
GS_FONTS_OTHER=		ghostscript-fonts-other-6.0.tar.gz

CONFLICTS=		ghostscript-[0-5]* ghostscript-x11-[0-5]*

PKG_INSTALLATION_TYPES=	overwrite pkgviews

DIST_SUBDIR=		ghostscript
NO_CONFIGURE=		YES
NO_BUILD=		YES
WRKSRC=			${WRKDIR}/fonts

FONTS_DIR=		${PREFIX}/share/ghostscript/fonts

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/ghostscript
	${INSTALL_DATA_DIR} ${FONTS_DIR}
	for ext in afm gsf pfa pfb pfm;				\
	do							\
		for f in ${WRKSRC}/*.$${ext};			\
		do						\
			${INSTALL_DATA} $${f} ${FONTS_DIR};	\
		done;						\
	done
	${INSTALL_DATA} ${WRKSRC}/fonts.dir ${FONTS_DIR}
	${INSTALL_DATA} ${WRKSRC}/fonts.scale ${FONTS_DIR}
	${INSTALL_DATA} ${FILESDIR}/fonts.alias ${FONTS_DIR}

.include "../../mk/bsd.pkg.mk"
