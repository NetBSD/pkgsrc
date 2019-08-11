# $NetBSD: Makefile,v 1.13 2019/08/11 13:20:45 wiz Exp $

DISTNAME=	bareword-filehandles-0.007
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/I/IL/ILMARI/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/bareword-filehandles
COMMENT=	Perl 5 module which disables bareword filehandles
LICENSE=	${PERL5_LICENSE}

BUILD_DEPENDS+=	p5-ExtUtils-Depends-[0-9]*:../../devel/p5-ExtUtils-Depends

USE_LANGUAGES=		c
PERL5_PACKLIST=		auto/bareword/filehandles/.packlist

.include "../../devel/p5-B-Hooks-OP-Check/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
