# $NetBSD: Makefile,v 1.10 2009/09/22 20:34:13 sno Exp $
#

DISTNAME=	Nmap-Parser-1.19
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Nmap/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Nmap-Parser/
COMMENT=	Parse nmap scan data with perl
LICENSE=	mit

DEPENDS+=	p5-XML-Twig>=3.16:../../textproc/p5-XML-Twig

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/Nmap/Parser/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
