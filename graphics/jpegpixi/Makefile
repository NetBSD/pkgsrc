# $NetBSD: Makefile,v 1.18 2022/08/09 12:08:35 jperkin Exp $

DISTNAME=		jpegpixi-1.1.1
PKGREVISION=		3
CATEGORIES=		graphics
# upstream is nonfunctional
MASTER_SITES=		${MASTER_SITE_BACKUP}

MAINTAINER=		gdt@NetBSD.org
#HOMEPAGE=		http://www.zero-based.org/software/jpegpixi/
COMMENT=		Low-loss JPEG interpolator to remove bad pixels

GNU_CONFIGURE=		yes
USE_PKGLOCALEDIR=	yes

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
