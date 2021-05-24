# $NetBSD: Makefile,v 1.23 2021/05/24 19:50:43 wiz Exp $

DISTNAME=	File-Type-0.22
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	15
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=File/}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Perl module for determining file type
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=		auto/File/Type/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
