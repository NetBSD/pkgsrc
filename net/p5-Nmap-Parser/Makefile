# $NetBSD: Makefile,v 1.3 2005/08/06 06:19:28 jlam Exp $
#

DISTNAME=	Nmap-Parser-0.80
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Nmap/}

MAINTAINER=	adrianp@NetBSD.org
HOMEPAGE=	http://www.nmapparser.com/
COMMENT=	Parse nmap scan data with perl

DEPENDS+=	p5-XML-Twig-[0-9]*:../../textproc/p5-XML-Twig

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		auto/Nmap/Parser/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
