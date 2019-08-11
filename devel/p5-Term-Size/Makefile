# $NetBSD: Makefile,v 1.21 2019/08/11 13:20:26 wiz Exp $

DISTNAME=	Term-Size-0.209
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Term/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Term-Size
COMMENT=	Perl extension for retrieving terminal size
LICENSE=	gnu-gpl-v2 OR artistic

PERL5_PACKLIST=		auto/Term/Size/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
