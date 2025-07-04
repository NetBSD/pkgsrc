# $NetBSD: Makefile,v 1.2 2025/07/04 08:47:02 wiz Exp $

DISTNAME=	cdk-perl-20250526
PKGNAME=	${DISTNAME:S/cdk-perl/p5-cdk/}
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	https://invisible-mirror.net/archives/cdk/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://invisible-mirror.net/cdk/cdk.html
COMMENT=	Perl bindings for CDK
#LICENSE=	mit, but not completely

GNU_CONFIGURE=	yes
USE_TOOLS+=	perl
TEST_TARGET=	test

.include "../../devel/cdk/buildlink3.mk"
.include "../../lang/perl5/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
