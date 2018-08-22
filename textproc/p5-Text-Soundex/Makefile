# $NetBSD: Makefile,v 1.6 2018/08/22 09:47:02 wiz Exp $

DISTNAME=	Text-Soundex-3.05
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Text/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Text-Soundex/
COMMENT=	Phonetic algorithm for indexing names by sound
LICENSE=	${PERL5_LICENSE}

CONFLICTS+=	perl<5.19.0

PERL5_PACKLIST=	auto/Text/Soundex/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
