# $NetBSD: Makefile,v 1.1.1.1 2003/09/04 13:30:54 xtraeme Exp $

DISTNAME=		Authen-SASL-Cyrus-0.07
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		security perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Authen/}

MAINTAINER=		cube@cubidou.net
HOMEPAGE=		http://search.cpan.org/dist/Authen-SASL-Cyrus/
COMMENT=		Perl module to handle Cyrus protocol for SASL authentication

DEPENDS+=		p5-Authen-SASL-[0-9]*:../../wip/p5-Authen-SASL

USE_BUILDLINK2=	YES
PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/Authen/SASL/Cyrus/.packlist

.include "../../security/cyrus-sasl2/buildlink2.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
