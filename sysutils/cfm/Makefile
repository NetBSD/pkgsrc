# $NetBSD: Makefile,v 1.3 2020/10/19 17:28:12 nia Exp $

DISTNAME=	cfm-0.6.6
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=willeccles/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://eccles.dev/cfm/
COMMENT=	Simple and fast TUI file manager with no dependencies
LICENSE=	mpl-2.0

MAKE_FLAGS+=	MANDIR=${PKGMANDIR}

CPPFLAGS.NetBSD+=	-D_NETBSD_SOURCE # dirfd

.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
