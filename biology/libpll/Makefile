# $NetBSD: Makefile,v 1.4 2024/01/24 17:35:53 thor Exp $

DISTNAME=	libpll-src-0.3.2
PKGNAME=	${DISTNAME:S/-src//}
PKGREVISION=	1
CATEGORIES=	biology
MASTER_SITES=	${MASTER_SITE_GITHUB:=xflouris/}
GITHUB_PROJECT=	libpll
GITHUB_RELEASE=	${PKGVERSION_NOREV}

MAINTAINER=	thomas.orgis@uni-hamburg.de
HOMEPAGE=	https://github.com/xflouris/libpll/
COMMENT=	High-performance software library for phylogenetic analysis
LICENSE=	gnu-agpl-v3

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes

USE_TOOLS+=	bison flex

CONFIGURE_ARGS+=	--disable-pdfman

# This assumes availability of sysinfo(), linux-specific
# resource monitoring.
ONLY_FOR_PLATFORM=	Linux-*-*

.include "../../mk/bsd.pkg.mk"
