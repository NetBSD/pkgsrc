# $NetBSD: Makefile,v 1.1.1.1 2007/07/28 09:54:52 seb Exp $
#

DISTNAME=	CAM-PDF-1.10
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/C/CD/CDOLAN/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/CAM-PDF/
COMMENT=	Perl 5 PDF manipulation library

USE_LANGUAGES=	# empty

DEPENDS+=	p5-Crypt-RC4>=2.02:../../security/p5-Crypt-RC4
DEPENDS+=	p5-Text-PDF>=0.29:../../textproc/p5-Text-PDF

PERL5_PACKLIST=	auto/CAM/PDF/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
