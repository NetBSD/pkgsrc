# $NetBSD: Makefile,v 1.12 2015/06/12 10:49:14 wiz Exp $

DISTNAME=	File-Path-2.09
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=File/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/File-Path/
COMMENT=	Perl5 module to create or remove directory trees
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=		auto/File/Path/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
