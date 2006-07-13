# $NetBSD: Makefile,v 1.6 2006/07/13 19:10:50 heinz Exp $
#

DISTNAME=		Crypt-RandPasswd-0.02
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		2
CATEGORIES=		security perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Crypt/}

MAINTAINER=		he@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Crypt-RandPasswd/
COMMENT=		Random password generator based on FIPS-181

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Crypt/RandPasswd/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
