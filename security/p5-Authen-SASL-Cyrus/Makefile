# $NetBSD: Makefile,v 1.28 2019/06/30 20:16:36 nia Exp $
#

DISTNAME=	Authen-SASL-Cyrus-0.13
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	7
CATEGORIES=	security perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Authen/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Authen-SASL-Cyrus
COMMENT=	Perl module to handle Cyrus protocol for SASL authentication

DEPENDS+=	p5-Authen-SASL-[0-9]*:../../security/p5-Authen-SASL

PERL5_PACKLIST=	auto/Authen/SASL/Cyrus/.packlist

.include "../../lang/perl5/module.mk"
.include "../../security/cyrus-sasl/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
