# $NetBSD: Makefile,v 1.9 2021/10/10 11:27:35 schmonz Exp $

DISTNAME=	oksh-7.0
CATEGORIES=	shells
MASTER_SITES=	${MASTER_SITE_GITHUB:=ibara/}
GITHUB_TAG=	${DISTNAME}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ibara/oksh/
COMMENT=	Portable OpenBSD ksh(1)
LICENSE=	original-bsd

WRKSRC=		${WRKDIR}/oksh-${PKGNAME_NOREV}

GNU_CONFIGURE=		yes
PKG_SHELL=		${PREFIX}/bin/oksh

.include "../../mk/bsd.pkg.mk"
