# $NetBSD: Makefile,v 1.1 2013/07/14 02:55:34 wen Exp $

DISTNAME=		Crypt-Random-TESHA2-0.01
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		security perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Crypt/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Crypt-Random-TESHA2/
COMMENT=		Random numbers using timer/schedule entropy
LICENSE=		${PERL5_LICENSE}

PKG_INSTALLATION_TYPES=	overwrite pkgviews

DEPENDS+=		p5-Digest-SHA>=5.22:../../security/p5-Digest-SHA
DEPENDS+=		p5-Time-HiRes>=1.9711:../../time/p5-Time-HiRes

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Crypt/Random/TESHA2/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
