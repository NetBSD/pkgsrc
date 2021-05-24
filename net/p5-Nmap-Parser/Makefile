# $NetBSD: Makefile,v 1.31 2021/05/24 19:53:33 wiz Exp $

DISTNAME=	Nmap-Parser-1.37
PKGNAME=	p5-${DISTNAME}0
PKGREVISION=	3
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Nmap/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Nmap-Parser
COMMENT=	Parse nmap scan data with perl
LICENSE=	mit

DEPENDS+=	p5-XML-Twig>=3.16:../../textproc/p5-XML-Twig

PERL5_PACKLIST=		auto/Nmap/Parser/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
