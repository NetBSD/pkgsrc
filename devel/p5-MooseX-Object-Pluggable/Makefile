# $NetBSD: Makefile,v 1.10 2012/10/03 21:55:21 wiz Exp $
#

DISTNAME=	MooseX-Object-Pluggable-0.0011
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	4
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=MooseX/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/MooseX-Object-Pluggable/
COMMENT=	Perl 5 module to add plugin support to Moose classes via roles
LICENSE=	gnu-gpl-v2 # OR artistic

DEPENDS+=	{perl>=5.10,p5-Module-Pluggable-[0-9]*}:../../devel/p5-Module-Pluggable
DEPENDS+=	p5-Moose>=0.35:../../devel/p5-Moose

PKG_DESTDIR_SUPPORT=	 user-destdir

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/MooseX/Object/Pluggable/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
