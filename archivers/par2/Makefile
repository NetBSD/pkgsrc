# $NetBSD: Makefile,v 1.28 2017/07/04 09:18:34 wiz Exp $

DISTNAME=	par2cmdline-0.7.3
PKGNAME=	${DISTNAME:S/cmdline//}
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_GITHUB:=BlackIkeEagle/}
GITHUB_PROJECT=	par2cmdline
GITHUB_RELEASE=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/BlackIkeEagle/par2cmdline
COMMENT=	PAR 2.0 compatible file verification and repair tool
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=		c c++
GNU_CONFIGURE=		yes
TEST_TARGET=		check

.include "../../mk/bsd.pkg.mk"
