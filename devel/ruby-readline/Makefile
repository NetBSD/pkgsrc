# $NetBSD: Makefile,v 1.46 2017/05/30 15:46:21 taca Exp $
#

DISTNAME=		${RUBY_DISTNAME}
PKGNAME=		${RUBY_PKGPREFIX}-${RUBY_EXTNAME}-${RUBY_VERSION}
PKGREVISION=		1
RUBY_EXTNAME=		readline
CATEGORIES=		devel ruby
MASTER_SITES=		${MASTER_SITE_RUBY}

MAINTAINER=		taca@NetBSD.org
HOMEPAGE=		${RUBY_HOMEPAGE}
COMMENT=		Ruby extension to readline library

USE_RUBY_EXTCONF=	yes
EXTRACT_ELEMENTS=	${RUBY_DISTNAME}/ext/readline \
			${RUBY_DISTNAME}/include ${RUBY_DISTNAME}/internal.h
WRKSRC=			${RUBY_WRKSRC}/ext/readline
MAKE_ENV+=		top_srcdir=../..

RUBY_DOCS=		README README.ja
INSTALLATION_DIRS=	${RUBY_DOC}/readline

.include "options.mk"
.include "../../lang/ruby/modules.mk"

post-install:
.for f in ${RUBY_DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DESTDIR}${PREFIX}/${RUBY_DOC}/readline
.endfor

.include "../../lang/ruby/Makefile.common"
.include "../../mk/bsd.pkg.mk"
