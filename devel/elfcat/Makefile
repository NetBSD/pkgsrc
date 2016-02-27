# $NetBSD: Makefile,v 1.1 2016/02/27 17:13:37 kamil Exp $

DISTNAME=	elfcat-1.0.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=randomstuff/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.rog
HOMEPAGE=	${MASTER_SITE_GITHUB:=randomstuff/elfcat/}
COMMENT=	Dump sections or program entries from a ELF file
LICENSE=	mit

USE_TOOLS+=	automake autoconf autoreconf

GNU_CONFIGURE=	yes

pre-configure:
	${RUN} cd ${WRKSRC} && autoreconf -fiv

.include "../../devel/libelf/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
