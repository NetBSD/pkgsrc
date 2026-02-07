# $NetBSD: Makefile,v 1.20 2026/02/07 00:47:52 gdt Exp $

DISTNAME=	p1_utils-1.0.28
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_GITHUB:=processone/}
GITHUB_PROJECT=	p1_utils

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/processone/p1_utils
COMMENT=	Erlang Utility Modules from ProcessOne
LICENSE=	apache-2.0

# Leave a non-versioned symlink in place
post-install:
	${LN} -sf ${DISTNAME} ${DESTDIR}${PREFIX}/lib/erlang/lib/p1_utils

.include "../../lang/erlang/module.mk"
.include "../../mk/bsd.pkg.mk"
