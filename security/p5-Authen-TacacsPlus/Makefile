# $NetBSD: Makefile,v 1.10 2013/05/31 12:41:53 wiz Exp $
#

DISTNAME=	Authen-TacacsPlus-0.23
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	perl5 security
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Authen/}

MAINTAINER=	pettai@NetBSD.org
HOMEPAGE=	http://search.cpan.org/~mikem/Authen-TacacsPlus/TacacsPlus.pm
COMMENT=	Perl extension for authentication using tacacs+ server
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=	auto/Authen/TacacsPlus/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
