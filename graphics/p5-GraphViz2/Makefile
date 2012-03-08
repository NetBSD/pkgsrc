# $NetBSD: Makefile,v 1.1.1.1 2012/03/08 11:31:31 fhajny Exp $
#

DISTNAME=	GraphViz2-1.12
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=GraphViz2/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/GraphViz2/
COMMENT=	Wrapper for AT&T\'s Graphviz
LICENSE=	artistic-2.0

PKG_DESTDIR_SUPPORT=	user-destdir

BUILD_DEPENDS+=	p5-Test-Pod-[0-9]*:../../devel/p5-Test-Pod
DEPENDS+=	graphviz-[0-9]*:../../graphics/graphviz
DEPENDS+=	p5-Algorithm-Dependency>=1.110:../../devel/p5-Algorithm-Dependency
DEPENDS+=	p5-Capture-Tiny>=0.10:../../devel/p5-Capture-Tiny
DEPENDS+=	p5-Data-Section-Simple>=0.02:../../devel/p5-Data-Section-Simple
DEPENDS+=	p5-DBI>=1.616:../../databases/p5-DBI
DEPENDS+=	p5-File-Temp>=0.22:../../devel/p5-File-Temp
DEPENDS+=	p5-File-Which>=1.09:../../devel/p5-File-Which
DEPENDS+=	p5-HTML-Entities-Interpolate>=1.04:../../www/p5-HTML-Entities-Interpolate
DEPENDS+=	p5-HTML-Tree>=4.2:../../www/p5-HTML-Tree
DEPENDS+=	p5-HTTP-Tiny>=0.012:../../www/p5-HTTP-Tiny
DEPENDS+=	p5-Hash-FieldHash>=0.10:../../devel/p5-Hash-FieldHash
DEPENDS+=	p5-Log-Handler>=0.71:../../devel/p5-Log-Handler
DEPENDS+=	p5-Parse-RecDescent>=1.965.1:../../devel/p5-Parse-RecDescent
DEPENDS+=	p5-PathTools>=3.33:../../devel/p5-PathTools
DEPENDS+=	p5-Perl6-Slurp>=0.03:../../devel/p5-Perl6-Slurp
DEPENDS+=	p5-Pod-Simple>=3.16:../../textproc/p5-Pod-Simple
DEPENDS+=	p5-Scalar-List-Utils>=1.23:../../devel/p5-Scalar-List-Utils
DEPENDS+=	p5-Set-Array>=0.23:../../devel/p5-Set-Array
DEPENDS+=	p5-Text-Xslate>=1.2:../../textproc/p5-Text-Xslate
DEPENDS+=	p5-TimeDate>=1.20:../../time/p5-TimeDate
DEPENDS+=	p5-Tree-DAG_Node>=1.06:../../devel/p5-Tree-DAG_Node
DEPENDS+=	p5-Try-Tiny>=0.09:../../devel/p5-Try-Tiny
DEPENDS+=	p5-XML-Bare>=0.45:../../textproc/p5-XML-Bare
DEPENDS+=	p5-XML-Tiny>=2.06:../../textproc/p5-XML-Tiny

PERL5_MODULE_TYPE=	Module::Build
PERL5_PACKLIST=		auto/GraphViz2/.packlist
USE_LANGUAGES=		# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
