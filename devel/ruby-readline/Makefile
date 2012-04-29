# $NetBSD: Makefile,v 1.32 2012/04/29 16:43:49 taca Exp $
#

DISTNAME=		${RUBY_DISTNAME}
PKGNAME=		${RUBY_PKGPREFIX}-${RUBY_EXTNAME}-${RUBY_VERSION_FULL}
PKGREVISION=		1
RUBY_EXTNAME=		readline
CATEGORIES=		devel ruby
MASTER_SITES=		${MASTER_SITE_RUBY}

MAINTAINER=		taca@NetBSD.org
HOMEPAGE=		${RUBY_HOMEPAGE}
COMMENT=		Ruby extension to readline library

PKG_DESTDIR_SUPPORT=	user-destdir

USE_RUBY_EXTCONF=	yes
DISTINFO_FILE=		${RUBY_DISTINFO_FILE}
EXTRACT_ELEMENTS=	${RUBY_DISTNAME}/ext/readline
WRKSRC=			${RUBY_WRKSRC}/ext/readline

RUBY_DOCS=		README README.ja
INSTALLATION_DIRS=	${RUBY_DOC}/readline

post-install:
.for f in ${RUBY_DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DESTDIR}${PREFIX}/${RUBY_DOC}/readline
.endfor

.include "options.mk"
.include "../../lang/ruby/modules.mk"
.include "../../lang/ruby/Makefile.common"
.include "../../devel/readline/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
