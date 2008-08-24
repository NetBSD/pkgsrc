# $NetBSD: Makefile,v 1.7 2008/08/24 20:30:41 he Exp $
#

DISTNAME=	Nmap-Parser-1.16
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Nmap/}

MAINTAINER=	adrianp@NetBSD.org
HOMEPAGE=	http://www.nmapparser.com/
#HOMEPAGE=	http://search.cpan.org/dist/Nmap-Parser/
COMMENT=	Parse nmap scan data with perl

DEPENDS+=	p5-XML-Twig-[0-9]*:../../textproc/p5-XML-Twig

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/Nmap/Parser/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
