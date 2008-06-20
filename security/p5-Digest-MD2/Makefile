# $NetBSD: Makefile,v 1.17 2008/06/20 01:09:34 joerg Exp $
#

DISTNAME=		Digest-MD2-2.03
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5md2
PKGREVISION=		2
CATEGORIES=		security perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Digest/}

MAINTAINER=		pkgsrc-users@NetBSD.org
COMMENT=		Perl5 module for MD2

PKG_DESTDIR_SUPPORT=	user-destdir

CONFLICTS+=		p5-Digest-MD5<=2.12

PERL5_PACKLIST=		auto/Digest/MD2/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
