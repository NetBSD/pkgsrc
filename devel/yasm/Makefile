# $NetBSD: Makefile,v 1.7 2004/05/07 01:14:47 xtraeme Exp $
#

DISTNAME=	yasm-0.2.2
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://www.tortall.net/projects/yasm/releases/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.tortall.net/projects/yasm/
COMMENT=	Complete rewrite of the NASM assembler with BSD license

BUILD_USES_MSGFMT=	YES

USE_BUILDLINK3=		YES
GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
USE_PERL5=		build

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
