# $NetBSD: Makefile,v 1.2 2009/06/01 18:57:00 sno Exp $
#

DISTNAME=	LaTeX-Table-0.9.15
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=LaTeX/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/LaTeX-Table/
COMMENT=	Perl extension for the automatic generation of LaTeX tables
LICENSE=	gnu-gpl-v2 # OR artistic

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	p5-Moose-[0-9]*:../../devel/p5-Moose
DEPENDS+=	p5-Moose-Policy-[0-9]*:../../devel/p5-Moose-Policy
DEPENDS+=	p5-Template-Toolkit-[0-9]*:../../www/p5-Template-Toolkit

BUILD_DEPENDS+=	p5-Test-NoWarnings-[0-9]*:../../devel/p5-Test-NoWarnings

# Recommended modules
DEPENDS+=	p5-LaTeX-Driver-[0-9]*:../../print/p5-LaTeX-Driver
DEPENDS+=	p5-LaTeX-Encode-[0-9]*:../../print/p5-LaTeX-Encode
DEPENDS+=	p5-Number-Format-[0-9]*:../../textproc/p5-Number-Format
DEPENDS+=	p5-Text-CSV-[0-9]*:../../textproc/p5-Text-CSV

PERL5_MODULE_TYPE=	Module::Build
PERL5_PACKLIST=		auto/LaTeX/Table/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
