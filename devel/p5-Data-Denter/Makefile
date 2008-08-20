# $NetBSD: Makefile,v 1.1.1.1 2008/08/20 22:28:18 seb Exp $
#

DISTNAME=	Data-Denter-0.15
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Data/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Data-Denter/
COMMENT=	(deprecated) alternative Perl 5 module to Data::Dumper and Storable

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Data/Denter/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
