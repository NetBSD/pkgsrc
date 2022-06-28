# $NetBSD: Makefile,v 1.20 2022/06/28 11:34:38 wiz Exp $

DISTNAME=	Excel-Template-0.34
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	7
CATEGORIES=	math perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Excel/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Excel-Template
COMMENT=	Perl module for templating Excel files
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-IO-stringy-[0-9]*:../../devel/p5-IO-stringy
DEPENDS+=	p5-Spreadsheet-WriteExcel>=0.42:../../math/p5-Spreadsheet-WriteExcel
DEPENDS+=	p5-XML-Parser>=0.01:../../textproc/p5-XML-Parser

BUILD_DEPENDS+=	p5-Test-Deep>=0.095:../../devel/p5-Test-Deep
BUILD_DEPENDS+=	p5-Test-Exception>=0.21:../../devel/p5-Test-Exception

MAKE_ENV+=		PERL_USE_UNSAFE_INC=1
PERL5_PACKLIST=		auto/Excel/Template/.packlist
PERL5_MODULE_TYPE=	Module::Install::Bundled

post-extract:
	${FIND} ${WRKSRC} -name "*.pm" -type f -exec ${CHMOD} -x {} \;

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
