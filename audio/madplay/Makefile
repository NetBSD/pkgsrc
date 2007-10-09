# $NetBSD: Makefile,v 1.32 2007/10/09 20:13:40 hubertf Exp $
#

DISTNAME=	madplay-0.15.2b
PKGREVISION=	3
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=mad/}

MAINTAINER=	simonb@NetBSD.org
HOMEPAGE=	http://sourceforge.net/projects/mad/
COMMENT=	High-quality MPEG audio decoder

USE_PKGLOCALEDIR=	YES
GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
USE_TOOLS+=		msgfmt

# Avoid an ICE in gcc2 on sparc64
CONFIGURE_ENV+=		F77=${FALSE:Q}

.include "options.mk"

.include "../../audio/libid3tag/buildlink3.mk"
.include "../../audio/libmad/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
