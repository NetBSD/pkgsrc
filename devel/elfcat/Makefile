# $NetBSD: Makefile,v 1.3 2016/06/09 06:23:38 wiz Exp $

DISTNAME=	elfcat-1.0.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=randomstuff/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.rog
HOMEPAGE=	https://github.com/randomstuff/elfcat/
COMMENT=	Dump sections or program entries from a ELF file
LICENSE=	mit

USE_TOOLS+=	automake autoconf autoreconf pkg-config

GNU_CONFIGURE=	yes

pre-configure:
	${RUN} cd ${WRKSRC} && autoreconf -fiv

.include "../../devel/libelf/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
