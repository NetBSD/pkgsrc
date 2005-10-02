# $NetBSD: Makefile,v 1.14 2005/10/02 06:17:43 taca Exp $
#

DISTNAME=	${RUBY_DISTNAME}
PKGNAME=	${RUBY_PKGPREFIX}-digest-${RUBY_VERSION}
PKGREVISION=	2
CATEGORIES=	security ruby
MASTER_SITES=	${MASTER_SITE_RUBY}

MAINTAINER=	taca@NetBSD.org
HOMEPAGE=	${RUBY_HOMEPAGE}
COMMENT=	Ruby extension to message digest library

RUBY_HAS_ARCHLIB=	yes
USE_RUBY_EXTCONF=	yes
RUBY_EXTCONF_SUBDIRS=	. md5 rmd160 sha1 sha2
EXTRACT_ELEMENTS=	${RUBY_DISTNAME}/ext/digest
WRKSRC=			${RUBY_WRKSRC}/ext/digest

RUBY_DOCS=		digest.txt digest.txt.ja

post-install:
	${INSTALL_DATA_DIR} ${RUBY_DOCDIR}/digest
.for f in ${RUBY_DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_DOCDIR}/digest
.endfor

.include "../../lang/ruby/modules.mk"
.include "../../lang/ruby/Makefile.common"
.include "../../mk/bsd.pkg.mk"
