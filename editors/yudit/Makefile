# $NetBSD: Makefile,v 1.29 2020/01/26 17:31:08 rillig Exp $

DISTNAME=	yudit-2.9.2
CATEGORIES=	editors
MASTER_SITES=	http://yudit.org/download/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://yudit.org/
COMMENT=	Unicode Text Editor
LICENSE=	gnu-gpl-v2

MAKE_JOBS_SAFE=		no

USE_LANGUAGES=		c c++03
USE_TOOLS+=		gmake msgmerge
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-x

BUILDLINK_DEPMETHOD.libXt=	build

.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
