# $NetBSD: Makefile,v 1.1.1.1 2005/03/18 05:25:32 taca Exp $
#

DISTNAME=	${RUBY_DISTNAME}
PKGNAME=	${RUBY_PKGPREFIX}-digest-${RUBY_VERSION}
CATEGORIES=	security ruby
MASTER_SITES=	${MASTER_SITE_RUBY}

MAINTAINER=	taca@NetBSD.org
HOMEPAGE=	${RUBY_HOMEPAGE}
COMMENT=	Ruby extension to message digest library for ${RUBY_VERSION}

RUBY_HAS_ARCHLIB=	yes
RUBY_VERSION=		${RUBY16_VERSION}
USE_BUILDLINK3=		yes
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
