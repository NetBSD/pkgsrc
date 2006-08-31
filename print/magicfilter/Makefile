# $NetBSD: Makefile,v 1.50 2006/08/31 08:22:38 rillig Exp $

DISTNAME=	magicfilter-1.2
PKGREVISION=	5
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_SUNSITE:=system/printing/}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Customizable, extensible automatic printer filter

# Any version will do:
#
DEPENDS+=	a2ps-[0-9]*:../../print/a2ps
DEPENDS+=	netpbm-[0-9]*:../../graphics/netpbm
DEPENDS+=	papersize-[0-9]*:../../print/papersize

USE_TOOLS+=	gmake gs:run gzip
GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	GHOSTSCRIPT=${TOOLS_PATH.gs}
CONFIGURE_ENV+= GZIP=${TOOLS_GZIP_CMD:Q}
TEX_ACCEPTED=	teTeX3

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

INSTALLATION_DIRS+=	${FILTER_DIR}

GENERATE_PLIST+= \
	(cd ${WRKSRC}/filters;						\
	for f in *-filter; do						\
	  ${ECHO} ${FILTER_DIR}/"$$f";					\
	done;								\
	${ECHO} "@dirrm ${FILTER_DIR}");

post-install:
	set -e;								\
	cd ${WRKSRC}/filters;						\
	for f in *-filter; do						\
	  ${ECHO} "Installing $$f as ${PREFIX}/${FILTER_DIR}/$$f";	\
	  ${INSTALL_SCRIPT} "$$f" ${PREFIX}/${FILTER_DIR}/"$$f";	\
	done

.include "../../mk/tex.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
