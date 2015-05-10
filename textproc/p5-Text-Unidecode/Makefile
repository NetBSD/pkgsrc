# $NetBSD: Makefile,v 1.12 2015/05/10 03:02:05 mef Exp $

DISTNAME=	Text-Unidecode-1.23
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Text/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Text-Unidecode/
COMMENT=	Perl5 module that transliterates Unicode to US-ASCII
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=		auto/Text/Unidecode/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
