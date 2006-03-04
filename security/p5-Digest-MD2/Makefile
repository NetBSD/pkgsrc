# $NetBSD: Makefile,v 1.16 2006/03/04 21:30:36 jlam Exp $
#

DISTNAME=		Digest-MD2-2.03
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5md2
PKGREVISION=		2
CATEGORIES=		security perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Digest/}

MAINTAINER=		pkgsrc-users@NetBSD.org
COMMENT=		Perl5 module for MD2

CONFLICTS+=		p5-Digest-MD5<=2.12

PERL5_PACKLIST=		auto/Digest/MD2/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
