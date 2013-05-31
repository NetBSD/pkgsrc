# $NetBSD: Makefile,v 1.6 2013/05/31 12:40:27 wiz Exp $
#

DISTNAME=	Locale-PO-0.21
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Locale/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Locale-PO/
COMMENT=	Perl 5 module for manipulating .po entries from GNU gettext
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=		# empty

PERL5_PACKLIST=	auto/Locale/PO/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
