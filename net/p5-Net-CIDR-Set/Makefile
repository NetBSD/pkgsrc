# $NetBSD: Makefile,v 1.7 2013/05/31 12:41:37 wiz Exp $
#

DISTNAME=	Net-CIDR-Set-0.11
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	4
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Net/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Net-CIDR-Set/
COMMENT=	Perl 5 module to manipulate sets of IP addresses

PERL5_MODULE_TYPE=	Module::Build
USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Net/CIDR/Set/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
