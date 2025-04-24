# $NetBSD: Makefile,v 1.20 2025/04/24 14:14:25 wiz Exp $

DISTNAME=		jpegpixi-1.1.1
PKGREVISION=		4
CATEGORIES=		graphics
# upstream is nonfunctional
MASTER_SITES=		${MASTER_SITE_BACKUP}

MAINTAINER=		gdt@NetBSD.org
#HOMEPAGE=		http://www.zero-based.org/software/jpegpixi/
COMMENT=		Low-loss JPEG interpolator to remove bad pixels

GNU_CONFIGURE=		yes

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
