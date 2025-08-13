# $NetBSD: Makefile,v 1.16 2025/08/13 11:07:29 pho Exp $

DISTNAME=	cheapskate-0.1.1.2
PKGREVISION=	11
CATEGORIES=	textproc

MAINTAINER=	pho@cielonegro.org
COMMENT=	Experimental markdown processor
LICENSE=	modified-bsd

# Don't pull in wai and wai-extra as dependencies.
CONFIGURE_ARGS+=	-f-dingus

HASKELL_UNRESTRICT_DEPENDENCIES+=	\
	containers	\
	data-default	\
	mtl	\
	text

.include "../../textproc/hs-blaze-html/buildlink3.mk"
.include "../../devel/hs-data-default/buildlink3.mk"
.include "../../devel/hs-syb/buildlink3.mk"
.include "../../devel/hs-uniplate/buildlink3.mk"
.include "../../www/hs-xss-sanitize/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
