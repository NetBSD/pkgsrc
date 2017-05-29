# $NetBSD: Makefile,v 1.26 2017/05/29 11:43:36 wiz Exp $

DISTNAME=	par2cmdline-0.7.1
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
# tests 22-24 fail as of 0.7.1
# https://github.com/Parchive/par2cmdline/issues/102
TEST_TARGET=		check

.include "../../mk/bsd.pkg.mk"
