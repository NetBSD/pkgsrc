# $NetBSD: Makefile,v 1.9 2002/10/20 17:46:04 seb Exp $
# FreeBSD Id: Makefile,v 1.7 1997/06/24 18:43:23 jfitz Exp
#

DISTNAME=		Crypt-CBC-2.02
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5cbc
CATEGORIES=		security perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Crypt/}

MAINTAINER=		packages@netbsd.org
COMMENT=		perl5 cipher block chaining mode for various crypto algorithms

DEPENDS+=		p5-Digest-MD5>=2.16:../../security/p5-Digest-MD5

USE_BUILDLINK2=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Crypt/CBC/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
