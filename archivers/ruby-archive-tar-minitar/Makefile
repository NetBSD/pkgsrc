# $NetBSD: Makefile,v 1.7 2015/09/25 05:44:03 taca Exp $

DISTNAME=	archive-tar-minitar-0.5.2
PKGREVISION=	2
CATEGORIES=	graphics

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	# http://rubyforge.org/projects/ruwiki/
COMMENT=	Pure Ruby library for handling POSIX tar archives
LICENSE=	gnu-gpl-v2 OR gnu-gpl-v3 OR ruby-license

# XXX: graphics/ruby-color depends on minitar but using command minitar?

RUBYGEM_OPTIONS+=	--format-executable

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
