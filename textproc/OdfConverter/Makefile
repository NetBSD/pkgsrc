# $NetBSD: Makefile,v 1.62 2020/04/12 08:29:14 adam Exp $
#

DISTNAME=	OdfAddinForOffice-src-3.0
PKGNAME=	OdfConverter-3.0
PKGREVISION=	52
CATEGORIES=	converters textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=odf-converter/}
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://odf-converter.sourceforge.net/
COMMENT=	Converter between Microsoft Office 2007 and OpenOffice formats
LICENSE=	modified-bsd

# mono-basic DLLs are required at run-time (but not at build time).
DEPENDS+=	mono-basic-[0-9]*:../../lang/mono-basic

USE_LANGUAGES=	c
USE_TOOLS+=	gmake pkg-config

BUILD_DIRS=	source/Common/OdfZipUtils
BUILD_DIRS+=	source/Common/OdfConverterLib
BUILD_DIRS+=	source/Word/Converter
BUILD_DIRS+=	source/Presentation/Converter
BUILD_DIRS+=	source/Spreadsheet/Converter
BUILD_DIRS+=	source/AdditionalTools/zlib123/contrib/minizip
BUILD_DIRS+=	source/Shell/OdfConverter

MAKE_JOBS_SAFE=	no

INSTALLATION_DIRS=	bin share/doc/OdfConverter

#
# The Subversion repository has a number of file name case issues.  The
# essential ones are fixed here so that the build can complete on a
# case-sensitive filesystem.
#
FILE_CASE_FIXES=	${BUILD_DIRS}
FILE_CASE_FIXES+=	source/Shell/OdfConverter/OdfCommandLineException.cs
FILE_CASE_FIXES+=	source/Shell/OdfConverter/OdfConverter.cs
FILE_CASE_FIXES+=	source/Shell/OdfConverter/OoxValidator.cs
FILE_CASE_FIXES+=	source/Shell/OdfConverter/OdfValidator.cs
post-extract:
	cd ${WRKDIR} && mv "odf-converter-r5224/trunk" ${DISTNAME:Q}
	set -e; \
	find "${WRKSRC}" -name Makefile -o \
	    -name '[Mm][Aa][Kk][Ee][Ff][Ii][Ll][Ee]' -print | \
	  while read file; do \
	    dir=`dirname "$$file"`; mv "$$file" "$$dir/Makefile"; done
	set -e; files=""; \
	for file in ${FILE_CASE_FIXES}; do \
	  while [ -n "$$file" -a "$$file" != "." ]; do \
	    files="$$file $$files"; base=`basename "$$file"`; \
	    file=`dirname "$$file"`; \
	  done; \
	done; \
	for file in $$files; do \
	  base=`basename "$$file"`; subdir=`dirname "$$file"`; \
	  lcbase=`basename "$$file" | tr 'A-Z' 'a-z'`; \
	  subdir="${WRKSRC}/$$subdir"; \
	  if [ -e "$$subdir/$$lcbase" -a ! -e "$$subdir/$$base" ]; then \
	    mv "$$subdir/$$lcbase" "$$subdir/$$base"; \
	  fi; \
	done

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/source/Shell/OdfConverter/OdfConverter \
		${DESTDIR}${PREFIX}/bin/
	${INSTALL_DATA} ${WRKSRC}/source/Shell/OdfConverter/README.TXT \
		${DESTDIR}${PREFIX}/share/doc/OdfConverter/README.TXT

.include "../../lang/mono/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
