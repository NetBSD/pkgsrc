# $NetBSD: Makefile,v 1.24 2023/07/06 09:41:20 wiz Exp $

DISTNAME=	Authen-TacacsPlus-0.28
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	security perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Authen/}

MAINTAINER=	pettai@NetBSD.org
HOMEPAGE=	https://metacpan.org/pod/distribution/Authen-TacacsPlus/TacacsPlus.pm
COMMENT=	Perl extension for authentication using tacacs+ server
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=	auto/Authen/TacacsPlus/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
