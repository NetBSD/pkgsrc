# $NetBSD: Makefile,v 1.55 2009/06/16 15:25:32 joerg Exp $

DISTNAME=	magicfilter-1.2
PKGREVISION=	7
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_SUNSITE:=system/printing/}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Customizable, extensible automatic printer filter

# Any version will do:
#
DEPENDS+=	a2ps-[0-9]*:../../print/a2ps
DEPENDS+=	netpbm-[0-9]*:../../graphics/netpbm
DEPENDS+=	papersize-[0-9]*:../../print/papersize
DEPENDS+=	dvipsk-[0-9]*:../../print/dvipsk

USE_TOOLS+=	gmake gs:run gzip
GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	GHOSTSCRIPT=${TOOLS_PATH.gs}
CONFIGURE_ENV+= GZIP=${TOOLS_GZIP_CMD:Q}

FILTER_DIR=	libexec/magicfilter

.include "../../mk/bsd.prefs.mk"

BUILD_DEFS+=	PAPERSIZE
PAPERSIZE?=	A4
LOWER_PAPERSIZE_cmd=	${ECHO} ${PAPERSIZE} | ${TR} "[A-Z]" "[a-z]"
LOWER_PAPERSIZE=	${LOWER_PAPERSIZE_cmd:sh}

SUBST_CLASSES+=		mf
SUBST_STAGE.mf=		post-build
SUBST_MESSAGE.mf=	Adjusting paper size in filters.
SUBST_FILES.mf=		filters/*-filter
SUBST_SED.mf=		-e 's/-sOutputFile=-/& -sPAPERSIZE=${LOWER_PAPERSIZE:Q:Q}/'

SUBST_CLASSES+=		gs
SUBST_STAGE.gs=		post-configure
SUBST_MESSAGE.gs=	Adjusting ghostscript temporary directory.
SUBST_FILES.gs=		filters/filters2.h
SUBST_SED.gs=		-e 's,${PREFIX}/bin/gs,${SETENV} TEMP=$${TMPDIR:-/tmp} &,'

INSTALLATION_DIRS+=	bin ${FILTER_DIR} ${PKGMANDIR}/man8

GENERATE_PLIST+= \
	cd ${WRKSRC}/filters &&						\
	for f in *-filter; do						\
	  ${ECHO} ${FILTER_DIR}/"$$f";					\
	done;

post-install:
	set -e;								\
	cd ${WRKSRC}/filters;						\
	for f in *-filter; do						\
	  ${ECHO} "Installing $$f as ${PREFIX}/${FILTER_DIR}/$$f";	\
	  ${INSTALL_SCRIPT} "$$f" ${PREFIX}/${FILTER_DIR}/"$$f";	\
	done

.include "../../mk/bsd.pkg.mk"
