# $NetBSD: Makefile,v 1.32 2023/04/23 14:26:32 adam Exp $

DISTNAME=	Syntax-SourceHighlight-2.1.2
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	8
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/M/MA/MATLIB/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Syntax-SourceHighlight
COMMENT=	Perl binding to GNU source-highlight
LICENSE=	public-domain

BUILD_DEPENDS+=	p5-ExtUtils-PkgConfig>=1.12:../../devel/p5-ExtUtils-PkgConfig

PERL5_PACKLIST=	auto/Syntax/SourceHighlight/.packlist

USE_TOOLS+=	pkg-config

.include "../../lang/perl5/module.mk"
.include "../../textproc/source-highlight/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
