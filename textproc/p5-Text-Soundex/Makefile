# $NetBSD: Makefile,v 1.1 2014/07/18 08:27:11 obache Exp $

DISTNAME=	Text-Soundex-3.04
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Text/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Text-Soundex/
COMMENT=	Phonetic algorithm for indexing names by sound

CONFLICTS+=	perl<5.19.0

PERL5_PACKLIST=	auto/Text/Soundex/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
