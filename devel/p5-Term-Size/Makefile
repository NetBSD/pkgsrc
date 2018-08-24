# $NetBSD: Makefile,v 1.19 2018/08/24 09:31:22 wiz Exp $

DISTNAME=	Term-Size-0.209
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Term/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Term-Size/
COMMENT=	Perl extension for retrieving terminal size
LICENSE=	gnu-gpl-v2 OR artistic

PERL5_PACKLIST=		auto/Term/Size/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
