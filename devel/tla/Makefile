# $NetBSD: Makefile,v 1.7 2004/03/30 10:48:29 recht Exp $
#

DISTNAME=	tla-1.2
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU:=gnu-arch/}		\
		http://regexps.srparish.net/src/tla/	\
		http://arch.quackerhead.com/~lord/releases/tla/

MAINTAINER=	recht@NetBSD.org
HOMEPAGE=	http://regexps.srparish.net/www/
COMMENT=	Revision control system ideal for widely distributed development

DEPENDS+=	patch-[0-9]*:../../devel/patch
DEPENDS+=	diffutils-[0-9]*:../../devel/diffutils
DEPENDS+=	gtar-base-[0-9]*:../../archivers/gtar-base

WRKSRC=		${WRKDIR}/${DISTNAME}/src/=build
USE_GNU_TOOLS+=	make

HAS_CONFIGURE=		# defined
CONFIGURE_SCRIPT=	../configure
CONFIGURE_ARGS+=	--prefix=${PREFIX}
CONFIGURE_ARGS+=	--with-gnu-diff=${PREFIX}/bin/${GNU_PROGRAM_PREFIX}diff
CONFIGURE_ARGS+=	--with-gnu-diff3=${PREFIX}/bin/${GNU_PROGRAM_PREFIX}diff
CONFIGURE_ARGS+=	--with-gnu-patch=${PREFIX}/bin/${GNU_PROGRAM_PREFIX}patch
CONFIGURE_ARGS+=	--with-gnu-tar=${PREFIX}/bin/${GNU_PROGRAM_PREFIX}tar

HTMLDIR=	${PREFIX}/share/doc/html/arch
EXAMPLESDIR=	${PREFIX}/share/examples/arch
LOCALDIR=	${PREFIX}/libexec/arch/local

post-extract:
	${MKDIR} ${WRKSRC}

post-install:
	# Install arch documentation.
	${INSTALL_DATA_DIR} ${HTMLDIR}
	${CP} -R ${WRKDIR}/${DISTNAME}/src/docs-tla/html/* ${HTMLDIR}
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${HTMLDIR}
	${CHMOD} -R ugo-w ${HTMLDIR}

.include "../../mk/bsd.pkg.mk"
