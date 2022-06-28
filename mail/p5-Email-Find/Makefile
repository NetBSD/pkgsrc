# $NetBSD: Makefile,v 1.16 2022/06/28 11:34:24 wiz Exp $

DISTNAME=	Email-Find-0.10
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	13
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Email/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Email-Find
COMMENT=	Find RFC 822 email addresses in plain text
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Email-Valid>=0.179:../../mail/p5-Email-Valid
DEPENDS+=	p5-MailTools-[0-9]*:../../mail/p5-MailTools

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Email/Find/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
