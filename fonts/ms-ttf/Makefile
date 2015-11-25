# $NetBSD: Makefile,v 1.23 2015/11/25 12:50:14 jperkin Exp $

DISTNAME=	# empty
PKGNAME=	ms-ttf-20020306
PKGREVISION=	6
CATEGORIES=	fonts
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=corefonts/}
DISTFILES=	andale32.exe webdin32.exe trebuc32.exe georgi32.exe \
		verdan32.exe comic32.exe arialb32.exe impact32.exe \
		arial32.exe times32.exe courie32.exe

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://corefonts.sourceforge.net/
COMMENT=	TrueType fonts from Microsoft
LICENSE=	ms-ttf-license

RESTRICTED=	No redistribution in altered form

BUILD_DEPENDS+=	cabextract-[0-9]*:../../archivers/cabextract

NO_BIN_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}
NO_SRC_ON_CDROM=	${RESTRICTED}

NO_CONFIGURE=	yes
NO_BUILD=	yes

DIST_SUBDIR=	ms-ttf
EXTRACT_CMD=	${LOCALBASE}/bin/cabextract -q $${extract_file}
FONTDIR=	${PREFIX}/share/fonts/X11/TTF
DOCDIR=		${PREFIX}/share/doc/ms-ttf
FONTS_DIRS.ttf=	${FONTDIR}

INSTALLATION_DIRS=	${FONTDIR} ${DOCDIR}

post-extract:
	${RUN}								\
	for f in ${WRKSRC}/*.TTF ; do					\
		${MV} $$f `${ECHO} $$f | ${SED} 's|TTF$$|ttf|'`;	\
	done

do-install:
	cd ${WRKSRC} && for f in *.ttf ; do \
		${INSTALL_DATA} $$f ${DESTDIR}${FONTDIR}/$$f; \
	done
	${INSTALL_DATA} ${.CURDIR}/../../licenses/${LICENSE} ${DESTDIR}${DOCDIR}

.include "../../mk/bsd.pkg.mk"
