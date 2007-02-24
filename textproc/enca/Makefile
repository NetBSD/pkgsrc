# $NetBSD: Makefile,v 1.1.1.1 2007/02/24 22:49:11 wiz Exp $
#

DISTNAME=		enca-1.9
CATEGORIES=		converters
MASTER_SITES=		http://trific.ath.cx/Ftp/enca/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://trific.ath.cx/software/enca/
COMMENT=		Extremely Naive Charset Analyser

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake
PKGCONFIG_OVERRIDE+=	${WRKSRC}/enca.pc.in

.include "../../mk/bsd.pkg.mk"
