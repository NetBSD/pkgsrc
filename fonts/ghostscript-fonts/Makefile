# $NetBSD: Makefile,v 1.10 2004/04/24 22:46:10 jlam Exp $

DISTNAME=		ghostscript-fonts-6.0
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
GS_FONTS_STD=		ghostscript-fonts-std-6.0.tar.gz
GS_FONTS_OTHER=		ghostscript-fonts-other-6.0.tar.gz

CONFLICTS=		ghostscript-[0-5]* ghostscript-x11-[0-5]*

DIST_SUBDIR=		ghostscript
EXTRACT_ONLY=		# empty
USE_BUILDLINK2=		# defined
NO_CONFIGURE=		# defined
NO_BUILD=		# defined

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/ghostscript
	@cd ${PREFIX}/share/ghostscript;				\
	for file in ${GS_FONTS_STD} ${GS_FONTS_OTHER}; do		\
		extract_file="${_DISTDIR}/$${file}";			\
		${EXTRACT_CMD};						\
	done
	${INSTALL_DATA} ${FILESDIR}/fonts.alias \
		${PREFIX}/share/ghostscript/fonts/
	@for file in ${PREFIX}/share/ghostscript/fonts/*; do		\
		${CHMOD} ${SHAREMODE} $${file};				\
		${CHOWN} ${SHAREOWN}:${SHAREGRP} $${file};		\
	done

.include "../../mk/bsd.pkg.mk"
