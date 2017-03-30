# $NetBSD: Makefile,v 1.1 2017/03/30 14:23:41 fhajny Exp $

DISTNAME=	epam-1.0.2
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GITHUB:=processone/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://github.com/processone/epam/
COMMENT=	epam helper for Erlang / Elixir PAM authentication support
LICENSE=	gnu-gpl-v2

GITHUB_PROJECT=	epam

SUPERSEDES=	erlang-p1_epam-[0-9]*

GNU_CONFIGURE=	yes

MAKE_ENV+=	USE_GLOBAL_DEPS=true

LDFLAGS.SunOS+=	-lnsl

.include "../../lang/erlang/module.mk"
.include "../../mk/bsd.pkg.mk"
