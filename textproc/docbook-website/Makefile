# $NetBSD: Makefile,v 1.1.1.1 2003/01/11 17:16:17 grant Exp $
#

DISTNAME=	website-2.3
PKGNAME=	docbook-${DISTNAME}
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=docbook/}

MAINTAINER=	grant@netbsd.org
HOMEPAGE=	http://docbook.sourceforge.net/
COMMENT=	DocBook DTD for building websites

NO_BUILD=	# defined
NO_CONFIGURE=	# defined
NO_PATCH=	# defined

DOCDIR=		${PREFIX}/share/doc/docbook-website
EGDIR=		${PREFIX}/share/examples/docbook-website
WEBSITEDIR=	${PREFIX}/share/docbook-website

do-install:
	${INSTALL_DATA_DIR} ${DOCDIR}
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA_DIR} ${WEBSITEDIR}
	@cd ${WRKSRC}; ${PAX} -rw ChangeLog README VERSION WhatsNew	\
		${DOCDIR}
	@cd ${WRKSRC}/example; ${PAX} -rw . ${EGDIR}
	@cd ${WRKSRC}; ${PAX} -rw VERSION extensions xsl *.dtd *.mod	\
		${WEBSITEDIR}

.include "../../mk/bsd.pkg.mk"
