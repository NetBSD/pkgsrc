# $NetBSD: Makefile,v 1.3 2003/01/02 17:20:39 grant Exp $
#

DISTNAME=	docbook-xsl-1.58.1
PKGREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=docbook/}

MAINTAINER=	jmmv@netbsd.org
HOMEPAGE=	http://docbook.sourceforge.net/
COMMENT=	Docbook XSL modular stylesheet

DEPENDS=	docbook-xml>=4.2:../../textproc/docbook-xml

NO_BUILD=	YES
NO_CONFIGURE=	YES
NO_PATCH=	YES

DOCDIR=		${PREFIX}/share/doc/docbook-xsl
EGDIR=		${PREFIX}/share/examples/docbook-xsl
XSLDIR=		${PREFIX}/share/xsl/docbook
XSLMODS=	common extensions fo html htmlhelp images javahelp \
		lib manpages params profiling tools xhtml

do-install:
	${INSTALL_DATA_DIR} ${DOCDIR}
	cd ${WRKSRC}/doc && ${PAX} -rwpppm . ${DOCDIR}
	${INSTALL_DATA_DIR} ${EGDIR}
	cd ${WRKSRC}/template && ${PAX} -rwpppm . ${EGDIR}
	${INSTALL_DATA_DIR} ${XSLDIR}
	${INSTALL_DATA} ${WRKSRC}/VERSION ${XSLDIR}
	@for d in ${XSLMODS}; do \
	    ${ECHO} "${INSTALL_DATA_DIR} ${XSLDIR}/$$d"; \
	    ${ECHO} "cd ${WRKSRC} && ${PAX} -rwpppm $$d ${XSLDIR}/"; \
	    cd ${WRKSRC} && ${PAX} -rwpppm $$d ${XSLDIR}/; \
	done

.include "../../mk/bsd.pkg.mk"
