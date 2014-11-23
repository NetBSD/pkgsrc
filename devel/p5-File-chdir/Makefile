# $NetBSD: Makefile,v 1.17 2014/11/23 14:22:38 schmonz Exp $

DISTNAME=	File-chdir-0.1009
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=File/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/File-chdir/
COMMENT=	Perl module with a more sensible way to change directories
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	{perl>=5.10.0,p5-PathTools>=3.27}:../../devel/p5-PathTools

PERL5_PACKLIST=		auto/File/chdir/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
