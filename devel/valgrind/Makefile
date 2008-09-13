# $NetBSD: Makefile,v 1.5 2008/09/13 19:07:31 dholland Exp $
#

DISTNAME=		valgrind-2.4.0
PKGREVISION=		1
CATEGORIES=		devel
MASTER_SITES=		http://valgrind.org/downloads/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://valgrind.org/downloads/
COMMENT=		Debugging and profiling tools

USE_PKGLOCALEDIR=	yes
PKGCONFIG_OVERRIDE+=	${WRKSRC}/valgrind.pc.in
GNU_CONFIGURE=		yes

ONLY_FOR_PLATFORM=	Linux-*-*

USE_TOOLS+=		gmake perl

.include "../../mk/bsd.pkg.mk"
