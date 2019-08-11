# $NetBSD: Makefile,v 1.21 2019/08/11 13:19:29 wiz Exp $

DISTNAME=	File-Type-0.22
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	13
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=File/}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Perl module for determining file type
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=		auto/File/Type/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
