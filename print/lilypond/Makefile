# $NetBSD: Makefile,v 1.31 2005/02/10 12:06:47 jmmv Exp $
#

DISTNAME=	lilypond-2.4.3
PKGREVISION=	2
CATEGORIES=	print
MASTER_SITES=	http://lilypond.org/download/v2.4/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://lilypond.org/web/
COMMENT=	GNU Music Typesetter

DEPENDS+=	ec-fonts-mftraced-[0-9]*:../../fonts/ec-fonts-mftraced
BUILD_DEPENDS+=	bison>=1.875nb1:../../devel/bison

BUILDLINK_DEPENDS.mftrace+=	mftrace>=1.1.0

GNU_CONFIGURE=		YES
USE_BUILDLINK3=		YES
USE_PKGLOCALEDIR=	YES
USE_LANGUAGES=		c c++
USE_GNU_TOOLS+=		make
MAKEFILE=		GNUmakefile

USE_MAKEINFO=	YES
TEXINFO_REQD=	4.7
INFO_DIR=	info/lilypond
INFO_FILES=	lilypond.info lilypond-internals.info music-glossary.info
CONFIGURE_HAS_INFODIR=	NO
CONFIGURE_ARGS+=	--infodir=${PREFIX}/info

CONFIGURE_ARGS+=--disable-optimising
CONFIGURE_ENV+=	PYTHON=${PYTHONBIN}
PYTHON_VERSIONS_ACCEPTED= 21 23
# 22 has some regular expression problem

SCRIPTS_DIR=	share/lilypond/${PKGVERSION:S/nb${PKGREVISION}//}/scripts
PLIST_SUBST+=	SCRIPTS_DIR=${SCRIPTS_DIR}
MESSAGE_SUBST+=	SCRIPTS_DIR=${SCRIPTS_DIR}

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/${SCRIPTS_DIR}
	${INSTALL_DATA} ${WRKSRC}/buildscripts/out/lilypond-login ${PREFIX}/${SCRIPTS_DIR}
	${INSTALL_DATA} ${WRKSRC}/buildscripts/out/lilypond-profile ${PREFIX}/${SCRIPTS_DIR}

.include "../../fonts/mftrace/buildlink3.mk"
.include "../../lang/guile/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../print/teTeX-bin/kpathsea.buildlink3.mk"
.include "../../textproc/scrollkeeper/omf.mk"
.include "../../mk/emacs.mk"
.include "../../mk/ghostscript.mk"
.include "../../mk/bsd.pkg.mk"
