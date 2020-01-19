# $NetBSD: Makefile,v 1.1 2020/01/19 12:08:08 pho Exp $

DISTNAME=	cheapskate-0.1.1.1
CATEGORIES=	textproc

MAINTAINER=	pho@cielonegro.org
COMMENT=	Experimental markdown processor
LICENSE=	modified-bsd

# Don't pull in wai and wai-extra as dependencies.
CONFIGURE_ARGS+=	-f-dingus

.include "../../textproc/hs-blaze-html/buildlink3.mk"
.include "../../devel/hs-data-default/buildlink3.mk"
.include "../../devel/hs-syb/buildlink3.mk"
.include "../../devel/hs-uniplate/buildlink3.mk"
.include "../../www/hs-xss-sanitize/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
