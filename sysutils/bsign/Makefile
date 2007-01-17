# $NetBSD: Makefile,v 1.1.1.1 2007/01/17 23:36:33 agc Exp $

DISTNAME=	bsign_0.4.5
PKGNAME=	bsign-0.4.5
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_DEBIAN:=pool/main/b/bsign/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://packages.debian.org/unstable/admin/bsign.html
COMMENT=	Utility to embed a hash or signature into an executable

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}

GNU_CONFIGURE=	yes
USE_LANGUAGES+=	c c++
USE_TOOLS+=	gmake

.include "../../mk/bsd.pkg.mk"
