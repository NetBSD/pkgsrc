# $NetBSD: Makefile,v 1.6 2003/07/17 22:52:53 grant Exp $
#

DISTNAME=	egd-0.8
CATEGORIES=	security
MASTER_SITES=	ftp://ftp.lothar.com/linux/ \
		http://www.lothar.com/pub/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.lothar.com/tech/crypto/
COMMENT=	EGD: Entropy Gathering Daemon

DEPENDS+=	p5-SHA-[0-9]*:../../security/p5-SHA

USE_BUILDLINK2=	YES
PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/egd/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
