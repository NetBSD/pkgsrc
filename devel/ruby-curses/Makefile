# $NetBSD: Makefile,v 1.12 2008/03/13 21:55:48 jlam Exp $
#

DISTNAME=		${RUBY_DISTNAME}
PKGNAME=		${RUBY_PKGPREFIX}-curses-${RUBY_VERSION_SUFFIX}
PKGREVISION=		1
CATEGORIES=		devel ruby
MASTER_SITES=		${MASTER_SITE_RUBY}

MAINTAINER=		taca@NetBSD.org
HOMEPAGE=		${RUBY_HOMEPAGE}
COMMENT=		Ruby extension to curses library

PKG_DESTDIR_SUPPORT=	user-destdir

RUBY_HAS_ARCHLIB=	yes
USE_RUBY_EXTCONF=	yes
EXTRACT_ELEMENTS=	${RUBY_DISTNAME}/ext/curses
WRKSRC=			${RUBY_WRKSRC}/ext/curses

CURSES_EXAMPLES=	hello.rb rain.rb view.rb view2.rb
REPLACE_RUBY=		${CURSES_EXAMPLES}

post-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${RUBY_EXAMPLESDIR}/curses
.for f in ${CURSES_EXAMPLES}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DESTDIR}${RUBY_EXAMPLESDIR}/curses
.endfor

.include "../../lang/ruby/modules.mk"
.include "../../lang/ruby/Makefile.common"
.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/termcap.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
