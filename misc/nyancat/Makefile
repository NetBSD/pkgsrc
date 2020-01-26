# $NetBSD: Makefile,v 1.6 2020/01/26 17:31:44 rillig Exp $

DISTNAME=	nyancat-1.5.2
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_GITHUB:=klange/}

MAINTAINER=	fcambus@NetBSD.org
HOMEPAGE=	https://nyancat.dakko.us/
COMMENT=	Nyancat in your terminal
LICENSE=	modified-bsd

INSTALL_MAKE_FLAGS+=	MANDIR=${PKGMANDIR}

MANCOMPRESSED=	yes

CPPFLAGS.SunOS+=	-D__EXTENSIONS__

.include "../../mk/bsd.pkg.mk"
