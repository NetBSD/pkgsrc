# $NetBSD: Makefile,v 1.1.1.1 2003/12/02 23:22:50 recht Exp $
#

DISTNAME=	tla-1.1pre8
PKGNAME=	tla-1.1.0.8
WRKSRC=		${WRKDIR}/${DISTNAME}/src/=build
CATEGORIES=	devel
MASTER_SITES=	http://regexps.srparish.net/src/tla/

MAINTAINER=	schmonz@NetBSD.org
HOMEPAGE=	http://arch.fifthvision.net/bin/view/Arch/WebHome
COMMENT=	Revision control system ideal for widely distributed development

DEPENDS+=	patch-[0-9]*:../../devel/patch

USE_GMAKE=	# defined

HAS_CONFIGURE=		# defined
CONFIGURE_SCRIPT=	../configure
CONFIGURE_ARGS+=	--prefix ${PREFIX}
CONFIGURE_ARGS+=	--with-gnu-patch=${PREFIX}/bin/${GNU_PROGRAM_PREFIX}patch

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
