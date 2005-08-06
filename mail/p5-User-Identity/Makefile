# $NetBSD: Makefile,v 1.6 2005/08/06 06:19:22 jlam Exp $

DISTNAME=	User-Identity-0.90
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	mail perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=User/}

MAINTAINER=	adrianp@NetBSD.org
HOMEPAGE=	http://perl.overmeer.net/userid/
COMMENT=	Helps maintaining user information from various sources

DEPENDS+=	p5-Geography-Countries-[0-9]*:../../misc/p5-Geography-Countries

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=	auto/User/Identity/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
