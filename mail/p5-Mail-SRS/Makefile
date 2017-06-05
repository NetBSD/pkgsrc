# $NetBSD: Makefile,v 1.23 2017/06/05 14:24:07 ryoon Exp $

DISTNAME=	Mail-SRS-0.31
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	13
CATEGORIES=	mail perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Mail/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.libsrs2.org/
COMMENT=	SMTP envelope sender rewriting for SPF-compliant forwarding

CONFLICTS+=	libsrs2-[0-9]*

#DEPENDS+=	{perl>=5.8.1,p5-DB_File>=1.806}:../../databases/p5-DB_File
DEPENDS+=	p5-Digest-HMAC>=1.01:../../security/p5-Digest-HMAC
DEPENDS+=	p5-MLDBM>=2.01:../../databases/p5-MLDBM
#DEPENDS+=	p5-Storable>=2.04:../../devel/p5-Storable
#BUILD_DEPENDS+=	{perl>=5.6.2,p5-Test-Simple>=0.40}:../../devel/p5-Test-Simple

PERL5_PACKLIST=	auto/Mail/SRS/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
