# $NetBSD: Makefile,v 1.9.2.1 2006/12/09 10:17:47 salo Exp $
#

DISTNAME=		${RUBY_DISTNAME}
PKGNAME=		${RUBY_PKGPREFIX}-curses-${RUBY_VERSION_SUFFIX}
CATEGORIES=		devel ruby
MASTER_SITES=		${MASTER_SITE_RUBY}

PATCH_SITES=		${MASTER_SITE_LOCAL}
PATCHFILES=		ruby-1.8.5-curses-${RUBY18_PATCH_DATE}.patch.bz2
PATCH_DIST_STRIP=	-p3

MAINTAINER=		taca@NetBSD.org
HOMEPAGE=		${RUBY_HOMEPAGE}
COMMENT=		Ruby extension to curses library

RUBY_HAS_ARCHLIB=	yes
USE_RUBY_EXTCONF=	yes
EXTRACT_ELEMENTS=	${RUBY_DISTNAME}/ext/curses
WRKSRC=			${RUBY_WRKSRC}/ext/curses

CURSES_EXAMPLES=	hello.rb rain.rb view.rb view2.rb
REPLACE_RUBY=		${CURSES_EXAMPLES}

post-install:
	${INSTALL_DATA_DIR} ${RUBY_EXAMPLESDIR}/curses
.for f in ${CURSES_EXAMPLES}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_EXAMPLESDIR}/curses
.endfor

.include "../../lang/ruby/modules.mk"
.include "../../lang/ruby/Makefile.common"
.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
