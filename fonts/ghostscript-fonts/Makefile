# $NetBSD: Makefile,v 1.3 2002/02/25 04:46:37 jlam Exp $

DISTNAME=		ghostscript-fonts-6.0
CATEGORIES=		fonts
MASTER_SITES+=		${MASTER_SITE_SOURCEFORGE:=gsfonts/} \
			ftp://ftp.cs.wisc.edu/ghost/aladdin/fonts/
DISTFILES=		${GS_FONTS_STD} ${GS_FONTS_OTHER}

MAINTAINER=		jlam@netbsd.org
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
NO_PATCH=		# defined
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
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${PREFIX}/share/ghostscript
	${CHMOD} -R a-w ${PREFIX}/share/ghostscript

.include "../../mk/bsd.pkg.mk"
