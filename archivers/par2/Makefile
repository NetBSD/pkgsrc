# $NetBSD: Makefile,v 1.24 2017/04/27 12:51:35 wiz Exp $

DISTNAME=	par2-0.7.0
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_GITHUB:=BlackIkeEagle/}
GITHUB_PROJECT=	par2cmdline
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/BlackIkeEagle/par2cmdline
COMMENT=	PAR 2.0 compatible file verification and repair tool
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=		c c++
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		autoconf automake autoreconf
GNU_CONFIGURE=		yes

pre-configure:
	cd ${WRKSRC} && autoreconf -fiv

.include "../../mk/bsd.pkg.mk"
