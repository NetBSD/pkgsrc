# $NetBSD: Makefile,v 1.2 2002/02/07 23:51:58 jonb Exp $
#

DISTNAME=	arch-1.0pre6
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	ftp://regexps.com/pub/src/arch/

MAINTAINER=	schmonz+netbsd@schmonz.com
HOMEPAGE=	http://www.regexps.com/
COMMENT=	revision control system ideal for widely distributed development

USE_GMAKE=	# defined

HAS_CONFIGURE=		# defined
CONFIGURE_SCRIPT=	../configure
CONFIGURE_ARGS+=	--prefix ${PREFIX}

WRKSRC=		${WRKDIR}/${DISTNAME}/src/=build
HTMLDIR=	${PREFIX}/share/doc/html/arch
EXAMPLESDIR=	${PREFIX}/share/examples/arch

post-extract:
	${MKDIR} ${WRKSRC}

post-install:
	# Install arch documentation.
	${INSTALL_DATA_DIR} ${HTMLDIR}
	${CP} -R ${WRKDIR}/${DISTNAME}/docs/html/* ${HTMLDIR}
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${HTMLDIR}
	${CHMOD} -R ugo-w ${HTMLDIR}

	# Install arch examples.
	${INSTALL_DATA_DIR} ${EXAMPLESDIR}
	${CP} -R ${WRKDIR}/${DISTNAME}/docs/examples/* ${EXAMPLESDIR}
	${RM} -rf ${EXAMPLESDIR}/browser/.arch-ids
	${RM} -rf ${EXAMPLESDIR}/notifier/.arch-ids
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${EXAMPLESDIR}
	${CHMOD} -R ugo-w ${EXAMPLESDIR}

.include "../../mk/bsd.pkg.mk"
