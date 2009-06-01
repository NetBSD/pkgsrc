# $NetBSD: Makefile,v 1.1.1.1 2009/06/01 18:49:13 sno Exp $
#

DISTNAME=	Text-CSV-1.12
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Text/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Text-CSV/
COMMENT=	Comma-separated values manipulator (using XS or PurePerl)
LICENSE=	gnu-gpl-v2 # OR artistic

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	p5-Text-CSV_XS>=0.65:../../textproc/p5-Text-CSV_XS

PERL5_PACKLIST=		auto/Text/CSV/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
