# $NetBSD: Makefile,v 1.9 2004/11/27 14:43:13 taca Exp $
#

DISTNAME=	${RUBY_DISTNAME}
PKGNAME=	${RUBY_PKGPREFIX}-digest-${RUBY_VERSION}
CATEGORIES=	security ruby
MASTER_SITES=	${MASTER_SITE_RUBY}

MAINTAINER=	taca@NetBSD.org
HOMEPAGE=	${RUBY_HOMEPAGE}
COMMENT=	Ruby extension to message digest library

USE_BUILDLINK3=		yes
USE_RUBY_EXTCONF=	yes
DISTINFO_FILE=		${RUBY_DISTINFO_FILE}
RUBY_EXTCONF_SUBDIRS=	. md5 rmd160 sha1 sha2
EXTRACT_ELEMENTS=	${RUBY_DISTNAME}/ext/digest
WRKSRC=			${RUBY_WRKSRC}/ext/digest

RUBY_DOCS=		digest.txt digest.txt.ja

post-install:
	${INSTALL_DATA_DIR} ${RUBY_DOCDIR}/digest
.for file in ${RUBY_DOCS}
	${INSTALL_DATA} ${WRKSRC}/${file} ${RUBY_DOCDIR}/digest
.endfor

.include "../../lang/ruby/modules.mk"
.include "../../lang/ruby/Makefile.common"
.include "../../mk/bsd.pkg.mk"
