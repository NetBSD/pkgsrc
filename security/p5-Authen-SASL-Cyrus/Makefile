# $NetBSD: Makefile,v 1.2 2003/09/09 09:58:11 salo Exp $
#

DISTNAME=	Authen-SASL-Cyrus-0.07
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	security perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Authen/}

MAINTAINER=	cube@cubidou.net
HOMEPAGE=	http://search.cpan.org/dist/Authen-SASL-Cyrus/
COMMENT=	Perl module to handle Cyrus protocol for SASL authentication

DEPENDS+=	p5-Authen-SASL-[0-9]*:../../security/p5-Authen-SASL

USE_BUILDLINK2=	YES
PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/Authen/SASL/Cyrus/.packlist

.include "../../lang/perl5/module.mk"
.include "../../security/cyrus-sasl2/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
