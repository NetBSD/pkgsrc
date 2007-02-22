# $NetBSD: Makefile,v 1.10 2007/02/22 19:27:10 wiz Exp $
#

PKGNAME=	cfengine-doc-${CFENGINE_VERSION}

.include "../../sysutils/cfengine2/Makefile.common"

COMMENT=	Documentation for cfengine

NO_CONFIGURE=	yes
NO_BUILD=	yes
INFO_FILES=	# PLIST

HTMLDIR=		${PREFIX}/share/doc/html/cfengine
INSTALLATION_DIRS=	${PKGINFODIR} ${HTMLDIR}

do-install:
	cd ${WRKSRC}/doc; for f in *.info *.info-[0-9]*; do		\
		${TEST} ! -f "$$f" ||					\
		${INSTALL_DATA} "$$f" ${PREFIX}/${PKGINFODIR};		\
	done
	${INSTALL_DATA} ${WRKSRC}/doc/cfengine-*.html ${HTMLDIR}

.include "../../mk/bsd.pkg.mk"
