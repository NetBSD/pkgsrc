# $NetBSD: Makefile,v 1.7 2012/10/03 21:55:56 wiz Exp $
#

DISTNAME=		valgrind-2.4.0
PKGREVISION=		2
CATEGORIES=		devel
MASTER_SITES=		http://valgrind.org/downloads/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://valgrind.org/downloads/
COMMENT=		Debugging and profiling tools
LICENSE=		gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

USE_PKGLOCALEDIR=	yes
PKGCONFIG_OVERRIDE+=	${WRKSRC}/valgrind.pc.in
GNU_CONFIGURE=		yes

ONLY_FOR_PLATFORM=	Linux-*-*

USE_TOOLS+=		gmake perl

.include "../../mk/bsd.pkg.mk"
