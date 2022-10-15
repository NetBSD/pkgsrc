# $NetBSD: Makefile,v 1.9 2022/10/15 12:04:42 triaxx Exp $

DISTNAME=	epam-1.0.12
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GITHUB:=processone/}
GITHUB_PROJECT=	epam

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/processone/epam
COMMENT=	Epam helper for Erlang / Elixir PAM authentication support
LICENSE=	gnu-gpl-v2

SUPERSEDES=	erlang-p1_epam-[0-9]*

GNU_CONFIGURE=	yes

LDFLAGS.SunOS+=	-lnsl -lsocket

.include "../../lang/erlang/module.mk"
.include "../../mk/pam.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
