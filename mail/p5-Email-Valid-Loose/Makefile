# $NetBSD: Makefile,v 1.10 2016/06/08 19:23:57 wiz Exp $

DISTNAME=		Email-Valid-Loose-0.05
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		8
CATEGORIES=		mail perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Email/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/perldoc?Email::Valid::Loose
COMMENT=		Email::Valid which allows dot before at mark

DEPENDS+=		p5-Email-Valid>=0.17:../../mail/p5-Email-Valid

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Email/Valid/Loose/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
