# $NetBSD: Makefile,v 1.9 2013/05/31 12:41:55 wiz Exp $
#

DISTNAME=		Crypt-SmbHash-0.12
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		5
CATEGORIES=		security perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Crypt/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Crypt-SmbHash/
COMMENT=		Perl5 module for generating LM/NT hashes

DEPENDS+=		p5-Digest-MD4>=1.3:../../security/p5-Digest-MD4

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		auto/Crypt/SmbHash/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
