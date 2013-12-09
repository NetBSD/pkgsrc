# $NetBSD: Makefile,v 1.7 2013/12/09 14:17:51 obache Exp $
#

VER=		0.9.9
DISTNAME=	biblatex-biber
PKGNAME=	p5-biblatex-biber-${VER}
PKGREVISION=	3
CATEGORIES=	print
MASTER_SITES=	http://sourceforge.net/projects/biblatex-biber/files/biblatex-biber/${VER}/
# TODO: can I express this with MASTER_SITES_SOURCEFORGE ?

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://biblatex-biber.sourceforge.net/
COMMENT=	Replacement of bibtex for users of BibLaTeX
DIST_SUBDIR=	${DISTNAME}-${VER}
LICENSE=	gnu-gpl-v1 OR artistic-2.0

# TODO: Look for the dependencies in Build.PL.
# no - that's for building the self-contained binary, which we won't.

WRKSRC=			${WRKDIR}/biblatex-biber-v0.9.9	# XXX not ${VER} - that only works for >= 1.0

PERL5_MODULE_TYPE=	Module::Build
PERL5_PACKLIST=		auto/Biber/Config/.packlist
USE_LANGUAGES=		# empty
USE_TOOLS+=		perl
REPLACE_PERL+=		bin/biber

DEPENDS+=		p5-Data-Compare-[0-9]*:../../devel/p5-Data-Compare
DEPENDS+=		p5-Data-Dump-[0-9]*:../../devel/p5-Data-Dump
DEPENDS+=		p5-Date-Simple-[0-9]*:../../devel/p5-Date-Simple
DEPENDS+=		p5-File-Slurp-[0-9]*:../../devel/p5-File-Slurp
DEPENDS+=		p5-File-Slurp-Unicode-[0-9]*:../../devel/p5-File-Slurp-Unicode
DEPENDS+=		p5-List-AllUtils-[0-9]*:../../devel/p5-List-AllUtils
DEPENDS+=		p5-Log-Log4perl-[0-9]*:../../devel/p5-Log-Log4perl
DEPENDS+=		p5-Regexp-Common-[0-9]*:../../textproc/p5-Regexp-Common
DEPENDS+=		{perl>=5.15.9,p5-Unicode-Collate>=0.89}:../../converters/p5-Unicode-Collate
DEPENDS+=		p5-XML-LibXML-Simple-[0-9]*:../../textproc/p5-XML-LibXML-Simple
DEPENDS+=		p5-XML-LibXSLT-[0-9]*:../../textproc/p5-XML-LibXSLT
DEPENDS+=		p5-XML-Writer-[0-9]*:../../textproc/p5-XML-Writer
DEPENDS+=		p5-XML-Writer-String-[0-9]*:../../textproc/p5-XML-Writer-String
DEPENDS+=		p5-Business-ISSN-[0-9]*:../../wip/p5-Business-ISSN
DEPENDS+=		p5-Business-ISMN-[0-9]*:../../wip/p5-Business-ISMN

DEPENDS+=		p5-Readonly-XS-[0-9]*:../../devel/p5-Readonly-XS
DEPENDS+=		tex-biblatex-1.7:../../print/tex-biblatex

DEPENDS+=		p5-IPC-Run3-[0-9]*:../../devel/p5-IPC-Run3
DEPENDS+=		p5-Text-BibTeX-[0-9]*:../../textproc/p5-Text-BibTeX
DEPENDS+=		p5-libwww-[0-9]*:../../www/p5-libwww

BUILD_DEPENDS+=		p5-ExtUtils-LibBuilder>=0.4:../../devel/p5-ExtUtils-LibBuilder
BUILD_DEPENDS+=		p5-Config-AutoConf>=0.1:../../devel/p5-Config-AutoConf

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"


post-install:
		${INSTALL_PROGRAM_DIR} ${DESTDIR}${PREFIX}/bin
		${INSTALL_SCRIPT} ${WRKSRC:Q}/bin/biber ${DESTDIR}${PREFIX}/bin

