# $NetBSD: Makefile,v 1.8 2005/06/23 16:56:31 taca Exp $
#

DISTNAME=	xmlrpc4r-1_7_16
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME:S/_/./g}
PKGREVISION=	2
CATEGORIES=	net ruby
MASTER_SITES=	http://www.fantasy-coders.de/ruby/xmlrpc4r/

MAINTAINER=	neumann@s-direktnet.de
HOMEPAGE=	http://www.fantasy-coders.de/ruby/xmlrpc4r/
COMMENT=	Implementation of the XML-RPC protocol for Ruby

USE_RUBY_INSTALL=	yes
NO_BUILD=		yes
REPLACE_RUBY_DIRS=	${WRKSRC}/samples
REPLACE_FILE_PAT=	*.rb *.cgi *.fcgi

DEPENDS+= ${RUBY_PKGPREFIX}-xmlparser>=0.6.8:../../textproc/ruby-xmlparser

post-install:
	${INSTALL_DATA_DIR} ${RUBY_DOCDIR}/xmlrpc
	${INSTALL_DATA} ${WRKSRC}/README ${RUBY_DOCDIR}/xmlrpc
	${INSTALL_DATA} ${WRKSRC}/doc/*.css ${RUBY_DOCDIR}/xmlrpc
	${INSTALL_DATA} ${WRKSRC}/doc/*.html ${RUBY_DOCDIR}/xmlrpc
	${INSTALL_DATA} ${WRKSRC}/doc/*.rd ${RUBY_DOCDIR}/xmlrpc
	${INSTALL_DATA_DIR} ${RUBY_EXAMPLESDIR}/xmlrpc
	${CP} -r ${WRKSRC}/samples/*  ${RUBY_EXAMPLESDIR}/xmlrpc

.include "../../lang/ruby/modules.mk"
.include "../../mk/bsd.pkg.mk"
