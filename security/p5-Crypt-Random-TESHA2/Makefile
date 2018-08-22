# $NetBSD: Makefile,v 1.9 2018/08/22 09:46:24 wiz Exp $

DISTNAME=		Crypt-Random-TESHA2-0.01
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		6
CATEGORIES=		security perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Crypt/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Crypt-Random-TESHA2/
COMMENT=		Random numbers using timer/schedule entropy
LICENSE=		${PERL5_LICENSE}

#DEPENDS+=		{perl>=5.9.3,p5-Digest-SHA>=5.22}:../../security/p5-Digest-SHA
#DEPENDS+=		{perl>=5.10.0,p5-Time-HiRes>=1.9711}:../../time/p5-Time-HiRes

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Crypt/Random/TESHA2/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
