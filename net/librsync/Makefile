# $NetBSD: Makefile,v 1.2 2016/07/09 06:38:43 wiz Exp $

DISTNAME=	librsync-1.0.1
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=librsync/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://librsync.sourcefrog.net/
COMMENT=	rsync-like rolling checksum library

GITHUB_TAG=	f32ed26d02b4d59aa0db215fb58c7a2536d19cb9

LICENSE=	gnu-lgpl-v2.1

USE_LIBTOOL=	yes
USE_TOOLS+=	autoconf automake libtoolize perl

GNU_CONFIGURE=	yes

pre-configure:
	cd ${WRKSRC} && ./autogen.sh

.include "../../devel/popt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
