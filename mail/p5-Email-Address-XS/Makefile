# $NetBSD: Makefile,v 1.13 2022/09/30 12:00:15 wen Exp $

DISTNAME=	Email-Address-XS-1.05
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	mail perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Email/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Email-Address-XS
COMMENT=	Parse and format RFC 2822 email addresses and groups
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=	auto/Email/Address/XS/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
