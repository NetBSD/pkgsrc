# $NetBSD: Makefile,v 1.10 2023/01/09 17:19:51 fcambus Exp $

DISTNAME=	oksh-7.2
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
