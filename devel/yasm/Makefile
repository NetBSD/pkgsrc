# $NetBSD: Makefile,v 1.5 2004/02/14 17:21:39 jlam Exp $
#

DISTNAME=	yasm-0.2.2
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://www.tortall.net/projects/yasm/releases/

MAINTAINER=	xtraeme@NetBSD.org
HOMEPAGE=	http://www.tortall.net/projects/yasm/
COMMENT=	Complete rewrite of the NASM assembler with BSD license

BUILD_USES_MSGFMT=	YES

USE_BUILDLINK2=		YES
GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
USE_PERL5=		build

.include "../../converters/libiconv/buildlink2.mk"
.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
