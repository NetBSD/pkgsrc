# $NetBSD: Makefile,v 1.14 2005/03/21 23:49:48 recht Exp $
#

DISTNAME=	tla-1.3.1
CATEGORIES=	devel
MASTER_SITES=	http://www.gnuarch.org/releases/	\
		http://www.seyza.com/gnu-releases/
#${MASTER_SITE_GNU:=gnu-arch/}		\

MAINTAINER=	recht@NetBSD.org
HOMEPAGE=	http://regexps.srparish.net/www/
COMMENT=	Revision control system ideal for widely distributed development

DEPENDS+=	patch-[0-9]*:../../devel/patch
DEPENDS+=	diffutils-[0-9]*:../../devel/diffutils
DEPENDS+=	gtar-base-[0-9]*:../../archivers/gtar-base

PKG_INSTALLATION_TYPES=	overwrite pkgviews

WRKSRC=		${WRKDIR}/${DISTNAME}/src/=build
USE_GNU_TOOLS+=	make

HAS_CONFIGURE=		yes
CONFIGURE_SCRIPT=	../configure
CONFIGURE_ARGS+= --prefix=${PREFIX}
CONFIGURE_ARGS+= --with-gnu-diff=${PREFIX}/bin/${GNU_PROGRAM_PREFIX}diff
CONFIGURE_ARGS+= --with-gnu-diff3=${PREFIX}/bin/${GNU_PROGRAM_PREFIX}diff3
CONFIGURE_ARGS+= --with-gnu-patch=${PREFIX}/bin/${GNU_PROGRAM_PREFIX}patch
CONFIGURE_ARGS+= --with-gnu-tar=${PREFIX}/bin/${GNU_PROGRAM_PREFIX}tar

HTMLDIR=	${PREFIX}/share/doc/html/arch

post-extract:
	${MKDIR} ${WRKSRC}

post-install:
	# Install arch documentation.
	${INSTALL_DATA_DIR} ${HTMLDIR}
	cd ${WRKDIR}/${DISTNAME}/src/docs-tla/html && \
		${PAX} -s ',.*/\.arch-ids.*,,' -rwppm . ${HTMLDIR}
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${HTMLDIR}
	${CHMOD} -R ugo-w ${HTMLDIR}

.include "../../mk/bsd.pkg.mk"
