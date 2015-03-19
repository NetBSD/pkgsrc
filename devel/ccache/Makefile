# $NetBSD: Makefile,v 1.27 2015/03/19 18:33:43 tnn Exp $

DISTNAME=	ccache-3.2.1
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://samba.org/ftp/ccache/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ccache.samba.org/
COMMENT=	Cache for C/C++ compilers
LICENSE=	gnu-gpl-v3 AND modified-bsd AND public-domain AND zlib

GNU_CONFIGURE=		yes

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

.include "../../mk/bsd.prefs.mk"

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
