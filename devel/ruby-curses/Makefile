# $NetBSD: Makefile,v 1.15 2011/11/08 16:34:47 taca Exp $
#

DISTNAME=		${RUBY_DISTNAME}
PKGNAME=		${RUBY_PKGPREFIX}-${RUBY_EXTNAME}-${RUBY_VERSION_FULL}
RUBY_EXTNAME=		curses
CATEGORIES=		devel ruby
MASTER_SITES=		${MASTER_SITE_RUBY}

MAINTAINER=		taca@NetBSD.org
HOMEPAGE=		${RUBY_HOMEPAGE}
COMMENT=		Ruby extension to curses library

PKG_DESTDIR_SUPPORT=	user-destdir

USE_RUBY_EXTCONF=	yes
EXTRACT_ELEMENTS=	${RUBY_DISTNAME}/ext/curses
WRKSRC=			${RUBY_WRKSRC}/ext/curses

CURSES_EXAMPLES=	hello.rb rain.rb view.rb view2.rb
REPLACE_RUBY=		${CURSES_EXAMPLES}
INSTALLATION_DIRS=	${RUBY_EG}/curses

post-install:
.for f in ${CURSES_EXAMPLES}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DESTDIR}${PREFIX}/${RUBY_EG}/curses
.endfor

.include "../../lang/ruby/modules.mk"
.include "../../lang/ruby/Makefile.common"
.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/termcap.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
