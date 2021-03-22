# $NetBSD: Makefile,v 1.27 2021/03/22 13:21:53 schmonz Exp $

DISTNAME=	racc-1.5.2
PKGREVISION=	1
CATEGORIES=	devel

MAINTAINER=	taca@NetBSD.org
HOMEPAGE=	https://github.com/tenderlove/racc
COMMENT=	LALR(1) parser generator for Ruby
LICENSE=	gnu-lgpl-v2

RUBYGEM_OPTIONS+=	--format-executable

PLIST_VARS+=	racc_command

.include "../../lang/ruby/rubyversion.mk"

.if ${RUBY_VER} == "27" || ${RUBY_VER} == "30"
ALTERNATIVES_SRC=	# empty
post-install:
	${RM} -f ${DESTDIR}${PREFIX}/bin/racc${RUBY_SUFFIX}
.else
PLIST.racc_command=	yes
.endif

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
