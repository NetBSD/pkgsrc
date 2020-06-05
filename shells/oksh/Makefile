# $NetBSD: Makefile,v 1.5 2020/06/05 20:23:03 maya Exp $

DISTNAME=	oksh-6.7
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

# XXX remove the following line in oksh>6.7
LDFLAGS.Linux+=		-lrt

.include "../../mk/bsd.pkg.mk"
