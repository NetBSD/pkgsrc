# $NetBSD: Makefile,v 1.2 2016/03/01 20:17:46 joerg Exp $

DISTNAME=	elfcat-1.0.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=randomstuff/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.rog
HOMEPAGE=	${MASTER_SITE_GITHUB:=randomstuff/elfcat/}
COMMENT=	Dump sections or program entries from a ELF file
LICENSE=	mit

USE_TOOLS+=	automake autoconf autoreconf pkg-config

GNU_CONFIGURE=	yes

pre-configure:
	${RUN} cd ${WRKSRC} && autoreconf -fiv

.include "../../devel/libelf/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
