# $NetBSD: Makefile,v 1.11 2023/08/24 15:46:18 schmonz Exp $

DISTNAME=	oksh-7.3
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

# <https://www.perkin.org.uk/posts/solaris-portability-flock.html>

.include "../../mk/bsd.pkg.mk"
