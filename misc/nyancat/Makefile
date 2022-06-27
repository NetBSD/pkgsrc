# $NetBSD: Makefile,v 1.7 2022/06/27 15:29:16 fcambus Exp $

DISTNAME=	nyancat-1.5.2
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_GITHUB:=klange/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://nyancat.dakko.us/
COMMENT=	Nyancat in your terminal
LICENSE=	modified-bsd

INSTALL_MAKE_FLAGS+=	MANDIR=${PKGMANDIR}

MANCOMPRESSED=	yes

CPPFLAGS.SunOS+=	-D__EXTENSIONS__

.include "../../mk/bsd.pkg.mk"
