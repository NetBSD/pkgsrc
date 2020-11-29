# $NetBSD: Makefile,v 1.7 2020/11/29 19:31:43 schmonz Exp $

DISTNAME=	oksh-6.8.1
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
