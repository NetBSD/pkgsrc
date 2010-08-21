# $NetBSD: Makefile,v 1.16 2010/08/21 16:35:35 seb Exp $
#

DISTNAME=	egd-0.8
PKGREVISION=	3
CATEGORIES=	security
MASTER_SITES=	http://www.lothar.com/pub/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.lothar.com/tech/crypto/
COMMENT=	EGD: Entropy Gathering Daemon

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	p5-SHA-[0-9]*:../../security/p5-SHA

PERL5_PACKLIST=	auto/egd/.packlist

BROKEN=		Conflicts with dependency

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
