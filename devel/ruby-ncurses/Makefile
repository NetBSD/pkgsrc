# $NetBSD: Makefile,v 1.7 2008/04/04 15:30:00 jlam Exp $

DISTNAME=	ncurses-ruby-1.1
PKGNAME=	${RUBY_PKGPREFIX}-${GEM_NAME}
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://download.berlios.de/ncurses-ruby/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ncurses-ruby.berlios.de/
COMMENT=	Ruby interface to ncurses

USE_NCURSES=	yes	# mouse functions
GEM_NAME=	${DISTNAME:S/-ruby//}
GEM_BUILD=	gemspec
GEM_CLEANBUILD=	Makefile *.o ncurses_bin.${RUBY_DLEXT} mkmf.log

post-extract:
	${RUN} cp ${FILESDIR}/gemspec ${GEM_SPECFILE}

.include "../../misc/rubygems/rubygem.mk"

.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
