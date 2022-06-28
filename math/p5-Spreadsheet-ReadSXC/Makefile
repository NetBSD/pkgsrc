# $NetBSD: Makefile,v 1.17 2022/06/28 11:34:43 wiz Exp $
#

DISTNAME=	Spreadsheet-ReadSXC-0.24
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	math perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Spreadsheet/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Spreadsheet-ReadSXC
COMMENT=	Perl 5 module to extract OpenOffice 1.x spreadsheet data

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Spreadsheet/ReadSXC/.packlist

DEPENDS+=	p5-Archive-Zip-[0-9]*:../../archivers/p5-Archive-Zip
DEPENDS+=	p5-PerlIO-gzip-[0-9]*:../../devel/p5-PerlIO-gzip
DEPENDS+=	p5-XML-Parser-[0-9]*:../../textproc/p5-XML-Parser

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
