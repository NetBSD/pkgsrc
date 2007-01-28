# $NetBSD: Makefile,v 1.2 2007/01/28 15:18:48 taca Exp $

DISTNAME=	rubyzip-0.9.1
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME:S/ruby//}
CATEGORIES=	archivers
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=rubyzip/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://rubyzip.sourceforge.net/
COMMENT=	Ruby module for reading and writing zip files

NO_BUILD=		yes
USE_RUBY_INSTALL=	yes
REPLACE_RUBY_DIRS=	${WRKSRC}/samples
DOCS=			ChangeLog NEWS README
EXAMPLES=		example.rb example_filesystem.rb gtkRubyzip.rb \
			qtzip.rb write_simple.rb zipfind.rb

post-install:
	${INSTALL_DATA_DIR} ${RUBY_DOCDIR}/rubyzip
	${INSTALL_DATA_DIR} ${RUBY_EXAMPLESDIR}/rubyzip
.for f in ${DOCS}
	cd ${WRKSRC}; ${INSTALL_DATA} ${f} ${RUBY_DOCDIR}/rubyzip
.endfor
.for f in ${EXAMPLES}
	cd ${WRKSRC}/samples; ${INSTALL_DATA} ${f} ${RUBY_EXAMPLESDIR}/rubyzip
.endfor

.include "../../lang/ruby/modules.mk"
.include "../../mk/bsd.pkg.mk"
