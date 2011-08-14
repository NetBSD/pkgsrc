# $NetBSD: Makefile,v 1.6 2011/08/14 12:26:30 obache Exp $

DISTNAME=	Perl6-Export-Attrs-0.0.3
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	4
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/D/DC/DCONWAY/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Perl6-Export-Attrs/
COMMENT=	Perl 5 module implementing Perl 6 symbol export mechanism

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	{p5-Attribute-Handlers>=0,perl>=5.10.0}:../../devel/p5-Attribute-Handlers
DEPENDS+=	p5-version-[0-9]*:../../devel/p5-version

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Perl6/Export/Attrs/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
