# $NetBSD: Makefile,v 1.4 2025/11/17 11:00:35 wiz Exp $

DISTNAME=	empty-0.6.20b
CATEGORIES=	devel
MASTER_SITES=	https://downloads.sourceforge.net/project/empty/empty/empty-0.6.20b/
EXTRACT_SUFX=	.tgz

MAINTAINER=	dave@weller-fahy.com
HOMEPAGE=	https://downloads.sourceforge.net/project/empty/empty/empty-0.6.20b/
COMMENT=	Simple replacement for expect
LICENSE=	modified-bsd

BUILDLINK_TRANSFORM.SunOS+=	rm:-lutil

.include "../../mk/bsd.pkg.mk"
