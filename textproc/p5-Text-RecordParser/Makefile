# $NetBSD: Makefile,v 1.10 2013/05/31 12:42:17 wiz Exp $
#

DISTNAME=	Text-RecordParser-v1.5.0
PKGNAME=	p5-${DISTNAME:S/v1/1/}
PKGREVISION=	3
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Text/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Text-RecordParser/
COMMENT=	Perl5 extension to read record-oriented files
LICENSE=	gnu-gpl-v2

DEPENDS+=	p5-Class-Accessor>=0:../../devel/p5-Class-Accessor
DEPENDS+=	p5-IO-stringy-[0-9]*:../../devel/p5-IO-stringy
DEPENDS+=	p5-List-MoreUtils-[0-9]*:../../devel/p5-List-MoreUtils
DEPENDS+=	p5-Readonly-[0-9]*:../../devel/p5-Readonly

# Recommended dependencies
DEPENDS+=	p5-GraphViz-[0-9]*:../../graphics/p5-GraphViz
DEPENDS+=	p5-Readonly-XS-[0-9]*:../../devel/p5-Readonly-XS
DEPENDS+=	p5-Text-TabularDisplay>=1.22:../../textproc/p5-Text-TabularDisplay

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Text/RecordParser/.packlist
PERL5_MODULE_TYPE=	Module::Build

USE_TOOLS+=perl

REPLACE_PERL+=		bin/tab2graph	blib/script/tab2graph
REPLACE_PERL+=		bin/tablify	blib/script/tablify
REPLACE_PERL+=		bin/tabmerge	blib/script/tabmerge

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
