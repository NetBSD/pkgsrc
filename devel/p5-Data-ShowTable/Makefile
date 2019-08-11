# $NetBSD: Makefile,v 1.31 2019/08/11 13:19:12 wiz Exp $

DISTNAME=	Data-ShowTable-4.6
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	5
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Data/}

MAINTAINER=	bad@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Data-ShowTable
COMMENT=	Perl module to print arrays of data in nicely formatted listings
LICENSE=	gnu-gpl-v2

PERL5_PACKLIST=		auto/Data/ShowTable/.packlist
REPLACE_PERL+=		showtable

pre-configure:
	${FIND} ${WRKSRC} -name "*.orig" -type f -exec ${RM} {} \;

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
