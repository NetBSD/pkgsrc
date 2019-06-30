# $NetBSD: Makefile,v 1.15 2019/06/30 20:16:58 nia Exp $
#

DISTNAME=	Text-Aspell-0.09
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	11
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Text/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Text-Aspell
COMMENT=	Perl interface to the GNU Aspell library

BUILD_DEPENDS+=	aspell-en>0:../../textproc/aspell-en

PERL5_PACKLIST=		auto/Text/Aspell/.packlist

.include "../../textproc/aspell/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
