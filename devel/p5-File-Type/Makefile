# $NetBSD: Makefile,v 1.19 2017/06/05 14:23:01 ryoon Exp $

DISTNAME=	File-Type-0.22
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	11
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=File/}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Perl module for determining file type
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=		auto/File/Type/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
