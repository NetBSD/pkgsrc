# $NetBSD: Makefile,v 1.10 2005/08/06 06:19:29 jlam Exp $
#

DISTNAME=	egd-0.8
PKGREVISION=	1
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
