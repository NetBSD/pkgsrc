# $NetBSD: Makefile,v 1.3 2016/09/14 20:53:56 wiedi Exp $

DISTNAME=	nyancat-1.5.1
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_GITHUB:=klange/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://nyancat.dakko.us/
COMMENT=	Nyancat in your terminal
LICENSE=	modified-bsd

INSTALL_MAKE_FLAGS+=	MANDIR=${PKGMANDIR}

MANCOMPRESSED=	yes

CPPFLAGS.SunOS+=	-D__EXTENSIONS__

.include "../../mk/bsd.pkg.mk"
