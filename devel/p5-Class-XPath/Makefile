# $NetBSD: Makefile,v 1.18 2018/08/22 09:43:45 wiz Exp $

DISTNAME=	Class-XPath-1.4
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	11
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Class/}

MAINTAINER=	schmonz@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Class-XPath/
COMMENT=	Perl5 module for XPath-style matching in object trees
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=		auto/Class/XPath/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
