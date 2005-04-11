# $NetBSD: Makefile,v 1.4 2005/04/11 21:46:22 tv Exp $

DISTNAME=	User-Identity-0.90
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	mail perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=User/}

MAINTAINER=	adrianp@NetBSD.org
HOMEPAGE=	http://perl.overmeer.net/userid/
COMMENT=	Helps maintaining user information from various sources

DEPENDS+=	p5-Geography-Countries-[0-9]*:../../misc/p5-Geography-Countries
PERL5_REQD+=	5.6.0

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/User/Identity/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
