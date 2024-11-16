# $NetBSD: Makefile,v 1.10 2024/11/16 12:03:35 wiz Exp $

DISTNAME=	egypt-1.11
PKGREVISION=	3
CATEGORIES=	devel
MASTER_SITES=	${HOMEPAGE}download/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.gson.org/egypt/
COMMENT=	Simple tool for creating call graphs of C programs
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=	auto/egypt/.packlist
USE_LANGUAGES=	# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
