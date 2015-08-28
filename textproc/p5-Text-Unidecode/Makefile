# $NetBSD: Makefile,v 1.14 2015/08/28 22:46:28 mef Exp $

DISTNAME=	Text-Unidecode-1.24
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
