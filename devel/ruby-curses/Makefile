# $NetBSD: Makefile,v 1.21 2016/03/14 00:59:05 tnn Exp $
#

DISTNAME=		${RUBY_DISTNAME}
PKGREVISION=		2
PKGNAME=		${RUBY_PKGPREFIX}-${RUBY_EXTNAME}-${RUBY_VERSION_FULL}
RUBY_EXTNAME=		curses
CATEGORIES=		devel ruby
MASTER_SITES=		${MASTER_SITE_RUBY}

MAINTAINER=		taca@NetBSD.org
HOMEPAGE=		${RUBY_HOMEPAGE}
COMMENT=		Ruby extension to curses library

USE_RUBY_EXTCONF=	yes
EXTRACT_ELEMENTS=	${RUBY_DISTNAME}/ext/curses
WRKSRC=			${RUBY_WRKSRC}/ext/curses

CURSES_EXAMPLES=	hello.rb rain.rb view.rb view2.rb
REPLACE_RUBY=		${CURSES_EXAMPLES}
INSTALLATION_DIRS=	${RUBY_EG}/curses

RUBY_VERSION_SUPPORTED= 18

post-install:
.for f in ${CURSES_EXAMPLES}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DESTDIR}${PREFIX}/${RUBY_EG}/curses
.endfor

.include "../../lang/ruby/modules.mk"
.include "../../lang/ruby/Makefile.common"
.include "../../mk/curses.buildlink3.mk"
.include "../../mk/termcap.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
