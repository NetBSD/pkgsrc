# $NetBSD: Makefile,v 1.17 2023/07/06 09:39:55 wiz Exp $

DISTNAME=	RT-Authen-ExternalAuth-0.17
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	12
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=RT/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/RT-Authen-ExternalAuth
COMMENT=	RT extension for external authentication methods
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-perl-ldap-[0-9]*:../../databases/p5-perl-ldap
DEPENDS+=	p5-CGI-[0-9]*:../../www/p5-CGI
DEPENDS+=	p5-DBI-[0-9]*:../../databases/p5-DBI
DEPENDS+=	p5-Net-SSLeay-[0-9]*:../../security/p5-Net-SSLeay

MAKE_ENV+=	PERL_USE_UNSAFE_INC=1
PERL5_PACKLIST=	auto/RT/Authen/ExternalAuth/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
