# $NetBSD: Makefile,v 1.14 2008/01/27 16:46:46 taca Exp $

DISTNAME=	tmail.${VERS}
PKGNAME=	${RUBY_PKGPREFIX}-tmail-${VERS}
CATEGORIES=	mail ruby
MASTER_SITES=	http://rubyforge.org/frs/download.php/30630/

MAINTAINER=	taca@NetBSD.org
HOMEPAGE=	http://tmail.rubyforge.org/
COMMENT=	Mail manipulating library for Ruby including MIME multipart support

VERS=			1.2.1
RUBY_HAS_ARCHLIB=	yes
USE_RUBY_SETUP=		yes
RUBY_SETUP=		script/setup

WRKSRC=			${WRKDIR}/tmail-${VERS}
INSTALLATION_DIRS=	${RUBY_DOCDIR}/tmail ${RUBY_EXAMPLESDIR}/tmail/data
DOCS=			CHANGES LICENSE NOTES README

post-install:
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_DOCDIR}/tmail
.endfor
	${INSTALL_DATA} ${WRKSRC}/sample/*.rb ${RUBY_EXAMPLESDIR}/tmail
	${INSTALL_DATA} ${WRKSRC}/sample/data/* ${RUBY_EXAMPLESDIR}/tmail/data

.include "../../lang/ruby/modules.mk"
.include "../../mk/bsd.pkg.mk"
