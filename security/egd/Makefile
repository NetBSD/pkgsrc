# $NetBSD: Makefile,v 1.17 2010/10/08 04:39:37 obache Exp $
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

USE_TOOLS+=	perl

PERL5_PACKLIST=	auto/egd/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
