# $NetBSD: Makefile,v 1.1.1.1 2009/11/16 23:59:36 seb Exp $
#

DISTNAME=	Data-Dumper-Concise-1.001
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Data/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Data-Dumper-Concise/
COMMENT=	Perl 5 module to dump references with concision and deparsing
LICENSE=	${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Data/Dumper/Concise/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
