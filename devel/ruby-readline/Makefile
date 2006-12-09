# $NetBSD: Makefile,v 1.19.8.1 2006/12/09 10:17:47 salo Exp $
#

DISTNAME=		${RUBY_DISTNAME}
PKGNAME=		${RUBY_PKGPREFIX}-readline-${RUBY_VERSION_SUFFIX}
CATEGORIES=		devel ruby
MASTER_SITES=		${MASTER_SITE_RUBY}

MAINTAINER=		taca@NetBSD.org
HOMEPAGE=		${RUBY_HOMEPAGE}
COMMENT=		Ruby extension to readline library

RUBY_HAS_ARCHLIB=	yes
USE_RUBY_EXTCONF=	yes
EXTRACT_ELEMENTS=	${RUBY_DISTNAME}/ext/readline
WRKSRC=			${RUBY_WRKSRC}/ext/readline

RUBY_DOCS=		README README.ja

post-install:
	${INSTALL_DATA_DIR} ${RUBY_DOCDIR}/readline
.for f in ${RUBY_DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_DOCDIR}/readline
.endfor

.include "../../devel/readline/buildlink3.mk"
.include "../../lang/ruby/modules.mk"
.include "../../lang/ruby/Makefile.common"
.include "../../mk/bsd.pkg.mk"
