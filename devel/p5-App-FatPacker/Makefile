# $NetBSD: Makefile,v 1.6 2011/08/07 07:47:51 adam Exp $

DISTNAME=	App-FatPacker-0.009006
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=App/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/App-FatPacker/
COMMENT=	Perl5 module to pack your dependencies onto your script file
LICENSE=	${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir

REPLACE_PERL+=		bin/fatpack

PERL5_PACKLIST=		auto/App/FatPacker/.packlist

DEPENDS+=	{perl>=5.10.1,p5-File-Path>=2.07}:../../devel/p5-File-Path

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
