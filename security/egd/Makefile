# $NetBSD: Makefile,v 1.11 2006/03/04 21:30:33 jlam Exp $
#

DISTNAME=	egd-0.8
PKGREVISION=	1
CATEGORIES=	security
MASTER_SITES=	ftp://ftp.lothar.com/linux/ \
		http://www.lothar.com/pub/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.lothar.com/tech/crypto/
COMMENT=	EGD: Entropy Gathering Daemon

DEPENDS+=	p5-SHA-[0-9]*:../../security/p5-SHA

PERL5_PACKLIST=	auto/egd/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
