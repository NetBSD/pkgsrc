# $NetBSD: Makefile,v 1.39 2018/08/22 09:44:09 wiz Exp $
#

DISTNAME=	IO-stringy-2.111
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	4
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=IO/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/IO-stringy/
COMMENT=	Perl class for I/O on in-core objects like strings and arrays
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/IO/Stringy/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
