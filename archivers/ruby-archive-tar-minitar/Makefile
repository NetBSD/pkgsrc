# $NetBSD: Makefile,v 1.4 2010/09/10 03:58:06 taca Exp $

DISTNAME=	archive-tar-minitar-0.5.2
PKGREVISION=	2
CATEGORIES=	graphics

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://rubyforge.org/projects/ruwiki/
COMMENT=	Pure Ruby library for handling POSIX tar archives
LICENSE=	gnu-gpl-v2 OR gnu-gpl-v3 OR ruby-license

# XXX: graphics/ruby-color depends on minitar but using command minitar?
post-install:
	${MV} ${DESTDIR}${PREFIX}/bin/minitar \
		${DESTDIR}${PREFIX}/bin/minitar${RUBY_VER}

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
