# $NetBSD: Makefile,v 1.3 2002/03/07 13:22:33 seb Exp $

DISTNAME=	# empty
PKGNAME=	ms-ttf-20020306
PKGREVISION=	1
CATEGORIES=	fonts
MASTER_SITES=	http://www.microsoft.com/typography/downloads/ \
		http://www.asia.microsoft.com/typography/downloads/ \
		http://www.eu.microsoft.com/typography/downloads/
DISTFILES=	andale32.exe webdin32.exe trebuc32.exe georgi32.exe \
		verdan32.exe comic32.exe arialb32.exe impact32.exe \
		arial32.exe times32.exe courie32.exe

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.microsoft.com/typography/fontpack/
COMMENT=	TrueType fonts from Microsoft

BUILD_DEPENDS+=	cabextract-[0-9]*:../../archivers/cabextract

LICENSE=        ms-ttf-license
RESTRICTED=	No redistribution in altered form

NO_BIN_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}
NO_SRC_ON_CDROM=	${RESTRICTED}

NO_PATCH=       yes
NO_CONFIGURE=   yes
NO_BUILD=       yes

USE_X11BASE=    yes
DIST_SUBDIR=	ms-ttf
EVAL_PREFIX+=	CABEXTRACT_PREFIX=cabextract
EXTRACT_CMD=	${CABEXTRACT_PREFIX}/bin/cabextract -q $${extract_file}
FONTDIR=	${PREFIX}/lib/X11/fonts/TrueType
DOCDIR=		${PREFIX}/share/doc/ms-ttf

post-extract:
	${_PKG_SILENT}${_PKG_DEBUG}					\
	for f in ${WRKSRC}/*.TTF ; do					\
		${MV} $$f `echo $$f | ${SED} 's|TTF$$|ttf|'`;		\
	done

do-install:
	${INSTALL_DATA_DIR} ${FONTDIR}
	${INSTALL_DATA_DIR} ${DOCDIR}
	cd ${WRKSRC} && for f in *.ttf ; do \
		${INSTALL_DATA} $$f ${FONTDIR}/$$f; \
	done
	${INSTALL_DATA} ${.CURDIR}/../../licenses/${LICENSE} ${DOCDIR}

.include "../../mk/bsd.pkg.mk"
