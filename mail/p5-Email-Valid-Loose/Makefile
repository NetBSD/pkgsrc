# $NetBSD: Makefile,v 1.13 2019/07/01 21:35:47 nia Exp $

DISTNAME=		Email-Valid-Loose-0.05
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		10
CATEGORIES=		mail perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Email/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://metacpan.org/pod/Email::Valid::Loose
COMMENT=		Email::Valid which allows dot before at mark

DEPENDS+=		p5-Email-Valid>=0.17:../../mail/p5-Email-Valid

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Email/Valid/Loose/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
