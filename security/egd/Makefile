# $NetBSD: Makefile,v 1.27 2021/05/24 19:53:52 wiz Exp $
#

DISTNAME=	egd-0.8
PKGREVISION=	12
CATEGORIES=	security
MASTER_SITES=	http://www.lothar.com/pub/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.lothar.com/tech/crypto/
COMMENT=	EGD: Entropy Gathering Daemon

DEPENDS+=	p5-SHA-[0-9]*:../../security/p5-SHA

USE_TOOLS+=	perl

PERL5_PACKLIST=	auto/egd/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
