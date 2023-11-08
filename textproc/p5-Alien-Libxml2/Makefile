# $NetBSD: Makefile,v 1.18 2023/11/08 13:21:07 wiz Exp $

DISTNAME=	Alien-Libxml2-0.17
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	8
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Alien/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/pod/Alien::Libxml2
COMMENT=	Perl interface to libxml2
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=	auto/Alien/Libxml2/.packlist

DEPENDS+=	p5-Alien-Build>=1.60:../../devel/p5-Alien-Build
DEPENDS+=	p5-PkgConfig>=0.24026:../../devel/p5-PkgConfig

.include "../../textproc/libxml2/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
