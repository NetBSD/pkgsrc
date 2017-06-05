# $NetBSD: Makefile,v 1.24 2017/06/05 14:24:23 ryoon Exp $
#

DISTNAME=	Nmap-Parser-1.33
PKGNAME=	p5-${DISTNAME}0
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Nmap/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Nmap-Parser/
COMMENT=	Parse nmap scan data with perl
LICENSE=	mit

DEPENDS+=	p5-XML-Twig>=3.16:../../textproc/p5-XML-Twig

PERL5_PACKLIST=		auto/Nmap/Parser/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
