# $NetBSD: Makefile,v 1.2 2011/05/19 04:56:01 obache Exp $

DISTNAME=	Text-CSV-Encoded-0.10
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Text/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Text-CSV-Encoded/
COMMENT=	Encoding aware Text::CSV
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Text-CSV>=1.12:../../textproc/p5-Text-CSV

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Text/CSV/Encoded/.packlist

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
