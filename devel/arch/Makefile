# $NetBSD: Makefile,v 1.4 2002/02/16 15:48:20 wiz Exp $
#

DISTNAME=	arch-1.0pre7
PKGNAME=	arch-1.0.0.7
CATEGORIES=	devel
MASTER_SITES=	ftp://regexps.com/pub/src/arch/

MAINTAINER=	schmonz+netbsd@schmonz.com
HOMEPAGE=	http://www.regexps.com/
COMMENT=	revision control system ideal for widely distributed development

DEPENDS+=	patch>=2.5.4:../../devel/patch

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

	# Install GNU patch where it can be found
	${LN} -s ${LOCALBASE}/bin/gpatch ${PREFIX}/libexec/arch/arch/patch

.include "../../mk/bsd.pkg.mk"
