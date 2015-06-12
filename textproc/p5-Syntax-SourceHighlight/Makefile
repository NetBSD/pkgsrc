# $NetBSD: Makefile,v 1.4 2015/06/12 10:51:29 wiz Exp $

DISTNAME=	Syntax-SourceHighlight-1.1.2
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	textproc
MASTER_SITES=	http://search.cpan.org/CPAN/authors/id/M/MU/MURPHY/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Syntax-SourceHighlight/
COMMENT=	Perl binding to GNU source-highlight
#LICENSE=	# TODO: (see mk/license.mk)

BUILD_DEPENDS+=	p5-ExtUtils-PkgConfig>=1.12:../../devel/p5-ExtUtils-PkgConfig

PERL5_PACKLIST=	auto/Syntax/SourceHighlight/.packlist

.include "../../lang/perl5/module.mk"
.include "../../textproc/source-highlight/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
