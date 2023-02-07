# $NetBSD: Makefile,v 1.8 2023/02/07 01:41:09 pho Exp $

DISTNAME=	cheapskate-0.1.1.2
PKGREVISION=	5
CATEGORIES=	textproc

MAINTAINER=	pho@cielonegro.org
COMMENT=	Experimental markdown processor
LICENSE=	modified-bsd

# Don't pull in wai and wai-extra as dependencies.
CONFIGURE_ARGS+=	-f-dingus

HASKELL_UNRESTRICT_DEPENDENCIES+=	\
	text

.include "../../textproc/hs-blaze-html/buildlink3.mk"
.include "../../devel/hs-data-default/buildlink3.mk"
.include "../../devel/hs-syb/buildlink3.mk"
.include "../../devel/hs-uniplate/buildlink3.mk"
.include "../../www/hs-xss-sanitize/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
