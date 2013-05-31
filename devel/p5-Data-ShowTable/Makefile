# $NetBSD: Makefile,v 1.21 2013/05/31 12:40:13 wiz Exp $

DISTNAME=	Data-ShowTable-3.3
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	9
SVR4_PKGNAME=	p5dst
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Data/}

MAINTAINER=	bad@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Data-ShowTable/
COMMENT=	Perl module to print arrays of data in nicely formatted listings
LICENSE=	gnu-gpl-v2

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		auto/Data/ShowTable/.packlist
REPLACE_PERL+=		showtable

pre-configure:
	${FIND} ${WRKSRC} -name "*.orig" -type f -exec ${RM} {} \;

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
