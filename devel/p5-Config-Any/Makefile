# $NetBSD: Makefile,v 1.8 2009/11/22 12:10:51 seb Exp $

DISTNAME=	Config-Any-0.18
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Config/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Config-Any/
COMMENT=	Perl extension for handling config files

DEPENDS+=	{perl>=5.10,p5-Module-Pluggable>=3.01}:../../devel/p5-Module-Pluggable

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Config/Any/.packlist

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
