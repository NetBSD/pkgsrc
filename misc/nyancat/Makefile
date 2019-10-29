# $NetBSD: Makefile,v 1.5 2019/10/29 09:46:14 fcambus Exp $

DISTNAME=	nyancat-1.5.2
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_GITHUB:=klange/}

MAINTAINER=	fcambus@NetBSD.org
HOMEPAGE=	http://nyancat.dakko.us/
COMMENT=	Nyancat in your terminal
LICENSE=	modified-bsd

INSTALL_MAKE_FLAGS+=	MANDIR=${PKGMANDIR}

MANCOMPRESSED=	yes

CPPFLAGS.SunOS+=	-D__EXTENSIONS__

.include "../../mk/bsd.pkg.mk"
