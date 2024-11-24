# $NetBSD: Makefile,v 1.83 2024/11/24 09:19:21 wiz Exp $

DISTNAME=	MailTools-2.22
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	mail perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Mail/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/MailTools
COMMENT=	Perl5 modules related to mail applications
LICENSE=	${PERL5_LICENSE}

TOOL_DEPENDS+=	p5-Net>=1.09:../../net/p5-Net
DEPENDS+=	p5-TimeDate-[0-9]*:../../time/p5-TimeDate

PERL5_PACKLIST=	auto/MailTools/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
