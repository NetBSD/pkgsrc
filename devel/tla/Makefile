# $NetBSD: Makefile,v 1.23 2006/02/05 23:08:54 joerg Exp $
#

DISTNAME=	tla-1.3.3
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU:=gnu-arch/}		\
		http://www.gnuarch.org/releases/	\
		http://www.seyza.com/gnu-releases/

MAINTAINER=	recht@NetBSD.org
HOMEPAGE=	http://regexps.srparish.net/www/
COMMENT=	Revision control system ideal for widely distributed development

DEPENDS+=	patch-[0-9]*:../../devel/patch
DEPENDS+=	diffutils-[0-9]*:../../devel/diffutils
DEPENDS+=	gtar-base-[0-9]*:../../archivers/gtar-base

PKG_INSTALLATION_TYPES=	overwrite pkgviews

WRKSRC=		${WRKDIR}/${DISTNAME}/src/=build
USE_TOOLS+=	gmake

HAS_CONFIGURE=		yes
CONFIGURE_SCRIPT=	../configure
CONFIGURE_ARGS+= --prefix=${PREFIX:Q}
CONFIGURE_ARGS+= --with-gnu-diff=${PREFIX}/bin/${GNU_PROGRAM_PREFIX}diff
CONFIGURE_ARGS+= --with-gnu-diff3=${PREFIX}/bin/${GNU_PROGRAM_PREFIX}diff3
CONFIGURE_ARGS+= --with-gnu-patch=${PREFIX}/bin/${GNU_PROGRAM_PREFIX}patch
CONFIGURE_ARGS+= --with-gnu-tar=${PREFIX}/bin/${GNU_PROGRAM_PREFIX}tar

DOCDIR=	${PREFIX}/share/doc/tla

post-extract:
	${MKDIR} ${WRKSRC}

pre-configure:
	@${CP} ${PKGSRCDIR}/mk/gnu-config/config.guess ${WRKSRC}/../build-tools/gnu/
	@${CP} ${PKGSRCDIR}/mk/gnu-config/config.sub ${WRKSRC}/../build-tools/gnu/
	@${CP} ${PKGSRCDIR}/mk/gnu-config/config.guess ${WRKSRC}/../expat/conftools/
	@${CP} ${PKGSRCDIR}/mk/gnu-config/config.sub ${WRKSRC}/../expat/conftools/
	@${CP} ${PKGSRCDIR}/mk/gnu-config/config.guess ${WRKSRC}/../libneon/
	@${CP} ${PKGSRCDIR}/mk/gnu-config/config.sub ${WRKSRC}/../libneon/

post-install:
	# Install arch documentation.
	${INSTALL_DATA_DIR} ${DOCDIR}
	cd ${WRKDIR}/${DISTNAME}/src/docs-tla &&		\
		${FIND} . \( -name \*.css -or -name \*.html	\
			-or -name \*.txt \) -print		\
		| ${PAX} -rwppm ${DOCDIR}
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${DOCDIR}
	${FIND} ${DOCDIR} -type d -print | ${XARGS} ${CHMOD} ${PKGDIRMODE}
	${FIND} ${DOCDIR} -type f -print | ${XARGS} ${CHMOD} ${SHAREMODE}

.include "../../mk/bsd.pkg.mk"
