# $NetBSD: Makefile,v 1.1.1.1 2005/11/07 11:32:12 martti Exp $

DISTNAME=	Term-Size-0.2
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Term/}

MAINTAINER=	martti@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/POE-Component-SNMP
COMMENT=	Perl extension for retrieving terminal size

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		auto/Term/Size/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
