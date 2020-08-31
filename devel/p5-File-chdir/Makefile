# $NetBSD: Makefile,v 1.26 2020/08/31 18:08:05 wiz Exp $

DISTNAME=	File-chdir-0.1010
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	6
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=File/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/File-chdir
COMMENT=	Perl module with a more sensible way to change directories
LICENSE=	${PERL5_LICENSE}

#DEPENDS+=	{perl>=5.10.0,p5-PathTools>=3.27}:../../devel/p5-PathTools

PERL5_PACKLIST=		auto/File/chdir/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
