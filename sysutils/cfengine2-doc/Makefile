# $NetBSD: Makefile,v 1.11 2008/06/20 01:09:35 joerg Exp $
#

PKGNAME=	cfengine-doc-${CFENGINE_VERSION}

PKG_DESTDIR_SUPPORT=	user-destdir

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
		${INSTALL_DATA} "$$f" ${DESTDIR}${PREFIX}/${PKGINFODIR}; \
	done
	${INSTALL_DATA} ${WRKSRC}/doc/cfengine-*.html ${DESTDIR}${HTMLDIR}

.include "../../mk/bsd.pkg.mk"
