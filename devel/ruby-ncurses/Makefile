# $NetBSD: Makefile,v 1.3 2006/02/03 15:18:59 taca Exp $

DISTNAME=	ncurses-ruby-1.0
PKGNAME=	${DISTNAME:S/ncurses-ruby/${RUBY_PKGPREFIX}-ncurses/}
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://download.berlios.de/ncurses-ruby/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	rasputnik@hellooperator.net
HOMEPAGE=	http://ncurses-ruby.berlios.de/
COMMENT=	Ruby interface to ncurses

USE_RUBY_EXTCONF=	yes
USE_NCURSES=		# mouse functions

EXAMPLES=		example.rb hello_ncurses.rb rain.rb read_line.rb \
			tclock.rb test_scanw.rb
.for f in ${EXAMPLES}
REPLACE_RUBY+=		sample/${f}
.endfor

post-install:
	${INSTALL_DATA_DIR} ${RUBY_EXAMPLESDIR}/ncurses
.for f in ${EXAMPLES}
	${INSTALL_DATA} ${WRKSRC}/examples/${f} ${RUBY_EXAMPLESDIR}/ncurses
.endfor

.include "../../devel/ncurses/buildlink3.mk"
.include "../../lang/ruby/modules.mk"
.include "../../mk/bsd.pkg.mk"
