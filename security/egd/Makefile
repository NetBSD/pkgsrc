# $NetBSD: Makefile,v 1.9 2005/07/13 18:01:37 jlam Exp $
#

DISTNAME=	egd-0.8
CATEGORIES=	security
MASTER_SITES=	ftp://ftp.lothar.com/linux/ \
		http://www.lothar.com/pub/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.lothar.com/tech/crypto/
COMMENT=	EGD: Entropy Gathering Daemon

DEPENDS+=	p5-SHA-[0-9]*:../../security/p5-SHA

PERL5_PACKLIST=	auto/egd/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
