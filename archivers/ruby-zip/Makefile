# $NetBSD: Makefile,v 1.3 2007/03/08 19:26:41 rillig Exp $

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

post-install:
	${INSTALL_DATA_DIR} ${RUBY_DOCDIR}/rubyzip
	${INSTALL_DATA_DIR} ${RUBY_EXAMPLESDIR}/rubyzip
	cd ${WRKSRC} && ${INSTALL_DATA} ChangeLog NEWS README ${RUBY_DOCDIR}/rubyzip
	cd ${WRKSRC}/samples && ${INSTALL_DATA} *.rb ${RUBY_EXAMPLESDIR}/rubyzip

.include "../../lang/ruby/modules.mk"
.include "../../mk/bsd.pkg.mk"
