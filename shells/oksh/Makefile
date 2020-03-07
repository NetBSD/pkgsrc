# $NetBSD: Makefile,v 1.3 2020/03/07 21:14:45 cheusov Exp $

DISTNAME=	oksh-6.5
PKGREVISION=	1
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
