# $NetBSD: Makefile,v 1.1 2013/07/06 01:05:56 rodent Exp $
#

DISTNAME=	HTML-FormatText-WithLinks-AndTables-0.02
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=HTML/}

MAINTAINER=	rodent@NetBSD.org
HOMEPAGE=	http://search.cpan.org/~sfryer/HTML-FormatText-WithLinks-AndTables/
COMMENT=	Converts HTML to Text with tables in tact
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-HTML-FormatText-WithLinks>=0:../../textproc/p5-HTML-FormatText-WithLinks

WRKSRC=		${WRKDIR}/HTML-FormatText-WithLinks-AndTables
PERL5_PACKLIST=	auto/HTML/FormatText/WithLinks/AndTables/.packlist
USE_LANGUAGES=	# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
