# $NetBSD: Makefile,v 1.17 2006/12/27 18:08:17 joerg Exp $

DISTNAME=		ghostscript-fonts-8.11
PKGREVISION=		1
CATEGORIES=		fonts
MASTER_SITES+=		${MASTER_SITE_SOURCEFORGE:=ghostscript/} \
			ftp://mirror.cs.wisc.edu/pub/mirrors/ghost/fonts/
DISTFILES=		${GS_FONTS_STD} ${GS_FONTS_OTHER}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://gs-fonts.sourceforge.net/
COMMENT=		Postscript fonts for Aladdin Ghostscript

PKG_DESTDIR_SUPPORT=	user-destdir

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
INSTALLATION_DIRS=	share/ghostscript/fonts
REQD_DIRS+=		share/ghostscript

do-install:
	for ext in afm gsf pfa pfb pfm;				\
	do							\
		for f in ${WRKSRC}/*.$${ext};			\
		do						\
			${INSTALL_DATA} $${f} ${DESTDIR}${FONTS_DIR};	\
		done;						\
	done
	${INSTALL_DATA} ${WRKSRC}/fonts.dir ${DESTDIR}${FONTS_DIR}
	${INSTALL_DATA} ${WRKSRC}/fonts.scale ${DESTDIR}${FONTS_DIR}
	${INSTALL_DATA} ${FILESDIR}/fonts.alias ${DESTDIR}${FONTS_DIR}

.include "../../mk/bsd.pkg.mk"
