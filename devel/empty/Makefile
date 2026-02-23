# $NetBSD: Makefile,v 1.5 2026/02/23 09:15:54 wiz Exp $

DISTNAME=	empty-0.6.20b
CATEGORIES=	devel
MASTER_SITES=	https://downloads.sourceforge.net/project/empty/empty/empty-0.6.20b/
EXTRACT_SUFX=	.tgz

MAINTAINER=	dave@weller-fahy.com
HOMEPAGE=	https://sourceforge.net/projects/empty/
COMMENT=	Simple replacement for expect
LICENSE=	modified-bsd

BUILDLINK_TRANSFORM.SunOS+=	rm:-lutil

.include "../../mk/bsd.pkg.mk"
