# $NetBSD: Makefile,v 1.29 2021/12/28 00:34:03 taca Exp $

DISTNAME=	racc-${RACC_VERSION}
CATEGORIES=	devel

MAINTAINER=	taca@NetBSD.org
HOMEPAGE=	https://github.com/tenderlove/racc
COMMENT=	LALR(1) parser generator for Ruby
LICENSE=	gnu-lgpl-v2

RACC_VERSION=	1.6.0

RUBYGEM_OPTIONS+=	--format-executable

PLIST_VARS+=	racc_command

.include "../../lang/ruby/rubyversion.mk"

.if !empty(RUBY_RACC_VERSION)

.  if ${RACC_VERSION} == "${RUBY_RACC_VERSION}"
.    error "${RUBY_PKGPREFIX}-base contains this package ${PKGBASE}."
.  endif

ALTERNATIVES_SRC=	# empty
post-install:
	${RM} -f ${DESTDIR}${PREFIX}/bin/racc${RUBY_SUFFIX}
.else
PLIST.racc_command=	yes
.endif

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
