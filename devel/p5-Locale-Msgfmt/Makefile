# $NetBSD: Makefile,v 1.11 2017/06/05 14:23:10 ryoon Exp $
#

DISTNAME=	Locale-Msgfmt-0.15
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	6
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Module/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Locale-Msgfmt/
COMMENT=	Perl 5 module to compile .po files to .mo files
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=		# empty

PERL5_PACKLIST=	auto/Locale/Msgfmt/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
