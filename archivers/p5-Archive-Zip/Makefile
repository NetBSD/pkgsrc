# $NetBSD: Makefile,v 1.36 2014/05/29 23:35:13 wiz Exp $

DISTNAME=	Archive-Zip-1.37
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
SVR4_PKGNAME=	p5zip
CATEGORIES=	archivers perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Archive/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Archive-Zip/
COMMENT=	Perl5 module interface to manipulate zip files
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	{perl>=5.10.1,p5-IO-Compress>=2.017}:../../devel/p5-IO-Compress	# Compress::Raw::Zlib>=2.017

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Archive/Zip/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
