# $NetBSD: Makefile,v 1.3 2019/08/11 13:18:42 wiz Exp $

DISTNAME=	egypt-1.10
PKGREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	${HOMEPAGE}download/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gson.org/egypt/
COMMENT=	Simple tool for creating call graphs of C programs
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=	auto/egypt/.packlist
USE_LANGUAGES=	# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
