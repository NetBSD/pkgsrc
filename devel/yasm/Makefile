# $NetBSD: Makefile,v 1.10 2005/07/16 01:19:09 jlam Exp $
#

DISTNAME=	yasm-0.2.2
PKGREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	http://www.tortall.net/projects/yasm/releases/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.tortall.net/projects/yasm/
COMMENT=	Complete rewrite of the NASM assembler with BSD license

BUILD_USES_MSGFMT=	YES

GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
USE_TOOLS+=		perl

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
