# $NetBSD: Makefile,v 1.1.1.1 2000/05/07 02:03:37 jlam Exp $

DISTNAME=		ghostscript-fonts-6.0
CATEGORIES=		print
MASTER_SITES+=		http://download.sourceforge.net/gs-fonts/ \
			ftp://ftp.cs.wisc.edu/ghost/aladdin/fonts/
DISTFILES=		${GS_FONTS_STD} ${GS_FONTS_OTHER}

#  Note: the following two are special files.  In the 5.50 directory
#  on the FTP site, there are symlinks:
#	ghostscript-fonts-other-5.50.tar.gz ->
#		../fonts/ghostscript-fonts-other-4.40.tar.gz
#  To avoid unnecessarily downloading distfiles, do not change these
#  when upgrading the port unless the symlinks/files really change.
#
GS_FONTS_STD=		ghostscript-fonts-std-6.0.tar.gz
GS_FONTS_OTHER=		ghostscript-fonts-other-6.0.tar.gz

MAINTAINER=		jlam@netbsd.org
HOMEPAGE=		http://gs-fonts.sourceforge.net/

CONFLICTS=		ghostscript-[0-5]* ghostscript-x11-[0-5]*

DIST_SUBDIR=		ghostscript
EXTRACT_ONLY=		# empty
NO_PATCH=		# defined
NO_CONFIGURE=		# defined
NO_BUILD=		# defined

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/ghostscript
	cd ${PREFIX}/share/ghostscript; \
		${PAX} -zrf ${_DISTDIR}/${GS_FONTS_STD}; \
		${PAX} -zrf ${_DISTDIR}/${GS_FONTS_OTHER}
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${PREFIX}/share/ghostscript
	${CHMOD} -R a-w ${PREFIX}/share/ghostscript

.include "../../mk/bsd.pkg.mk"
