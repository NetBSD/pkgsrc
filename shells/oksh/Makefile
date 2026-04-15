# $NetBSD: Makefile,v 1.14 2026/04/15 12:51:20 ktnb Exp $

DISTNAME=		oksh-7.8
CATEGORIES=		shells
MASTER_SITES=		${MASTER_SITE_GITHUB:=ibara/}
GITHUB_TAG=		${DISTNAME}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://github.com/ibara/oksh/
COMMENT=		Portable OpenBSD ksh(1)
LICENSE=		original-bsd

WRKSRC=			${WRKDIR}/oksh-${PKGNAME_NOREV}

GNU_CONFIGURE=		yes
PKG_SHELL=		${PREFIX}/bin/oksh

.include "../../mk/bsd.pkg.mk"
