# $NetBSD: Makefile,v 1.30 2022/01/16 14:55:18 taca Exp $

DISTNAME=	racc-1.6.0
CATEGORIES=	devel

MAINTAINER=	taca@NetBSD.org
HOMEPAGE=	https://github.com/tenderlove/racc
COMMENT=	LALR(1) parser generator for Ruby
LICENSE=	gnu-lgpl-v2

#
# Ruby 3.1 has the same conflicting version 1.6.0.
#
RUBY_VERSIONS_ACCEPTED=	26 27 30

RUBYGEM_OPTIONS+=	--format-executable

PLIST_VARS+=	racc_command

.include "../../lang/ruby/rubyversion.mk"

.if !empty(RUBY_RACC_VER)
ALTERNATIVES_SRC=	# empty
post-install:
	${RM} -f ${DESTDIR}${PREFIX}/bin/racc${RUBY_SUFFIX}
.else
PLIST.racc_command=	yes
.endif

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
