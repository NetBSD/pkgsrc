# $NetBSD: Makefile,v 1.31 2017/06/05 14:22:44 ryoon Exp $

DISTNAME=	Clone-0.39
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Clone/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Clone/
COMMENT=	Perl module for recursively copying datatypes
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=		auto/Clone/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
