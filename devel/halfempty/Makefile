# $NetBSD: Makefile,v 1.1 2020/01/09 12:12:17 wiz Exp $

DISTNAME=	halfempty-0.30
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=googleprojectzero/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/googleprojectzero/halfempty/
COMMENT=	Fast, parallel test case minimization tool
LICENSE=	apache-2.0

USE_TOOLS+=	gmake pkg-config

.include "../../devel/glib2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
