# $NetBSD: Makefile,v 1.1.1.1 2004/06/20 22:23:00 schmonz Exp $
#

DISTNAME=		Class-XPath-1.4
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Class/}

MAINTAINER=		schmonz@NetBSD.org
COMMENT=		Perl5 module for XPath-style matching in object trees

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Class/XPath/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
