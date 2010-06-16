# $NetBSD: Makefile,v 1.27 2010/06/16 19:36:28 drochner Exp $
#

DISTNAME=	yasm-1.0.1
CATEGORIES=	devel
MASTER_SITES=	http://www.tortall.net/projects/yasm/releases/

MAINTAINER=	shaun@inerd.com
HOMEPAGE=	http://www.tortall.net/projects/yasm/
COMMENT=	Complete rewrite of the NASM assembler with BSD license
LICENSE=	modified-bsd AND (artistic OR gnu-gpl-v2 OR gnu-lgpl-v2)

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=		msgfmt
GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
TEST_TARGET=		check

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
