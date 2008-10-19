# $NetBSD: Makefile,v 1.3 2008/10/19 19:17:50 he Exp $

DISTNAME=	Config-Any-0.14
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Config/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Config-Any/
COMMENT=	Perl extension for handling config files

DEPENDS+=	p5-Module-Pluggable>=3.01:../../devel/p5-Module-Pluggable

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Config/Any/.packlist

PKG_DESTDIR_SUPPORT=    user-destdir

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
