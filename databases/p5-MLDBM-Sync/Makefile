# $NetBSD: Makefile,v 1.33 2019/06/30 20:14:26 nia Exp $

DISTNAME=	MLDBM-Sync-0.30
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	11
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=MLDBM/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/MLDBM-Sync
COMMENT=	Perl5 module for safe concurrent access to MLDBM databases
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-MLDBM>=1:../../databases/p5-MLDBM
#DEPENDS+=	{perl>=5.7.3,p5-Digest-MD5-[0-9]*}:../../security/p5-Digest-MD5

PERL5_PACKLIST=		auto/MLDBM/Sync/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
