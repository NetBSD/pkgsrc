# $NetBSD: Makefile,v 1.6 2015/03/01 12:44:56 taca Exp $

DISTNAME=	archive-tar-minitar-0.5.2
PKGREVISION=	2
CATEGORIES=	graphics

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://rubyforge.org/projects/ruwiki/
COMMENT=	Pure Ruby library for handling POSIX tar archives
LICENSE=	gnu-gpl-v2 OR gnu-gpl-v3 OR ruby-license

# XXX: graphics/ruby-color depends on minitar but using command minitar?

RUBYGEM_OPTIONS+=	--format-executable

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
