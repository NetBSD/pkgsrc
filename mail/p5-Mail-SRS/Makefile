# $NetBSD: Makefile,v 1.1.1.1 2004/03/29 19:49:04 tv Exp $

DISTNAME=	Mail-SRS-0.30
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	mail perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Mail/}

MAINTAINER=	tv@duh.org
HOMEPAGE=	http://www.anarres.org/projects/srs/
COMMENT=	SMTP envelope sender rewriting for SPF-compliant forwarding

DEPENDS+=	p5-DB_File>=1.806:../../databases/p5-DB_File
DEPENDS+=	p5-Digest-HMAC>=1.01:../../security/p5-Digest-HMAC
DEPENDS+=	p5-MLDBM>=2.01:../../databases/p5-MLDBM
DEPENDS+=	p5-Storable>=2.04:../../devel/p5-Storable
BUILD_DEPENDS+=	p5-Test-Simple>=0.40:../../devel/p5-Test-Simple

USE_BUILDLINK3=	YES
PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/Mail/SRS/.packlist
PERL5_REQD=	5.6.0

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
