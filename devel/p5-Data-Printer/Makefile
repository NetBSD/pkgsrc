# $NetBSD: Makefile,v 1.14 2019/06/30 20:14:49 nia Exp $

DISTNAME=	Data-Printer-0.40
PKGNAME=	p5-${DISTNAME:S/_/./}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/G/GA/GARU/}
#ASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Data/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Data-Printer
COMMENT=	Colored pretty-print of Perl data structures and objects
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Clone-PP-[0-9]*:../../devel/p5-Clone-PP
DEPENDS+=	p5-File-HomeDir>=0.91:../../devel/p5-File-HomeDir
DEPENDS+=	p5-Package-Stash>=0.3:../../devel/p5-Package-Stash
DEPENDS+=	p5-Sort-Naturally-[0-9]*:../../devel/p5-Sort-Naturally

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Data/Printer/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
