# $NetBSD: Makefile,v 1.11 2003/07/21 16:43:15 martti Exp $
#

DISTNAME=	arch1.0pre25
PKGNAME=	arch-1.0.0.25
WRKSRC=		${WRKDIR}/${DISTNAME}/src/=build
CATEGORIES=	devel
MASTER_SITES=	http://regexps.srparish.net/src/arch/

MAINTAINER=	schmonz@NetBSD.org
HOMEPAGE=	http://arch.fifthvision.net/bin/view/Arch/WebHome
COMMENT=	Revision control system ideal for widely distributed development

USE_GMAKE=	# defined

HAS_CONFIGURE=		# defined
CONFIGURE_SCRIPT=	../configure
CONFIGURE_ARGS+=	--prefix ${PREFIX}

HTMLDIR=	${PREFIX}/share/doc/html/arch
EXAMPLESDIR=	${PREFIX}/share/examples/arch
LOCALDIR=	${PREFIX}/libexec/arch/local

post-extract:
	${MKDIR} ${WRKSRC}

post-install:
	# Install arch documentation.
	${INSTALL_DATA_DIR} ${HTMLDIR}
	${CP} -R ${WRKDIR}/${DISTNAME}/docs/html/* ${HTMLDIR}
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${HTMLDIR}
	${CHMOD} -R ugo-w ${HTMLDIR}

.include "../../mk/bsd.pkg.mk"
