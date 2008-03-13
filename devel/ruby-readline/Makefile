# $NetBSD: Makefile,v 1.23 2008/03/13 21:04:40 jlam Exp $
#

DISTNAME=		${RUBY_DISTNAME}
PKGNAME=		${RUBY_PKGPREFIX}-readline-${RUBY_VERSION_SUFFIX}
CATEGORIES=		devel ruby
MASTER_SITES=		${MASTER_SITE_RUBY}

MAINTAINER=		taca@NetBSD.org
HOMEPAGE=		${RUBY_HOMEPAGE}
COMMENT=		Ruby extension to readline library

PKG_DESTDIR_SUPPORT=	user-destdir

RUBY_HAS_ARCHLIB=	yes
USE_RUBY_EXTCONF=	yes
EXTRACT_ELEMENTS=	${RUBY_DISTNAME}/ext/readline
WRKSRC=			${RUBY_WRKSRC}/ext/readline

RUBY_DOCS=		README README.ja

post-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${RUBY_DOCDIR}/readline
.for f in ${RUBY_DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DESTDIR}${RUBY_DOCDIR}/readline
.endfor

.include "../../devel/readline/buildlink3.mk"
.include "../../lang/ruby/modules.mk"
.include "../../lang/ruby/Makefile.common"
.include "../../mk/bsd.pkg.mk"
