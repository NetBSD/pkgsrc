# $NetBSD: Makefile,v 1.21 2018/08/22 09:47:01 wiz Exp $
#

DISTNAME=	Text-RecordParser-1.6.5
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	4
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
DEPENDS+=	p5-Pod-Readme>=0:../../textproc/p5-Pod-Readme
DEPENDS+=	p5-Pod-Markdown>=0:../../textproc/p5-Pod-Markdown
DEPENDS+=	p5-Text-Autoformat-[0-9]*:../../textproc/p5-Text-Autoformat

BUILD_DEPENDS+=	p5-Test-Exception-[0-9]*:../../devel/p5-Test-Exception

# Recommended dependencies
DEPENDS+=	p5-GraphViz-[0-9]*:../../graphics/p5-GraphViz
DEPENDS+=	p5-Readonly-XS-[0-9]*:../../devel/p5-Readonly-XS
DEPENDS+=	p5-Text-TabularDisplay>=1.22:../../textproc/p5-Text-TabularDisplay

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Text/RecordParser/.packlist

USE_TOOLS+=perl

REPLACE_PERL+=		bin/tab2graph
REPLACE_PERL+=		bin/tablify
REPLACE_PERL+=		bin/tabmerge

# File is unwriteable but is generated during the build.
post-extract:
	${RM} -f ${WRKSRC}/README.md

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
