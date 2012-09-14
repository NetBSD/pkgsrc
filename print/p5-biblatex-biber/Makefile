# $NetBSD: Makefile,v 1.1 2012/09/14 13:20:45 is Exp $
#

VER=		0.9.9
DISTNAME=	biblatex-biber
PKGNAME=	p5-biblatex-biber-${VER}
CATEGORIES=	wip
MASTER_SITES=	http://sourceforge.net/projects/biblatex-biber/files/biblatex-biber/${VER}/
# TODO: can I express this with MASTER_SITES_SOURCEFORGE ?

MAINTAINER=	INSERT_YOUR_MAIL_ADDRESS_HERE
HOMEPAGE=	http://biblatex-biber.sourceforge.net/
COMMENT=	Replacement of bibtex for users of BibLaTeX
DIST_SUBDIR=	${DISTNAME}-${VER}
LICENSE=	gnu-gpl-v1 OR artistic-2.0

PKG_DESTDIR_SUPPORT=	user-destdir

# TODO: Look for the dependencies in Build.PL.
# no - that's for building the self-contained binary, which we won't.

WRKSRC=			${WRKDIR}/biblatex-biber-v0.9.9	# XXX not ${VER} - that only works for >= 1.0

PERL5_MODULE_TYPE=	Module::Build
PERL5_PACKLIST=		auto/Biber/Config/.packlist
USE_LANGUAGES=		# empty
USE_TOOLS=		perl
REPLACE_PERL+=		bin/biber

DEPENDS+=		p5-Data-Compare:../../devel/p5-Data-Compare
DEPENDS+=		p5-Data-Dump:../../devel/p5-Data-Dump
DEPENDS+=		p5-Date-Simple:../../devel/p5-Date-Simple
DEPENDS+=		p5-File-Slurp:../../devel/p5-File-Slurp
DEPENDS+=		p5-File-Slurp-Unicode:../../devel/p5-File-Slurp-Unicode
DEPENDS+=		p5-List-AllUtils:../../devel/p5-List-AllUtils
DEPENDS+=		p5-Log-Log4perl:../../devel/p5-Log-Log4perl
DEPENDS+=		p5-Regexp-Common:../../textproc/p5-Regexp-Common
DEPENDS+=		p5-Unicode-Collate>=0.89:../../converters/p5-Unicode-Collate
DEPENDS+=		p5-XML-LibXML-Simple:../../textproc/p5-XML-LibXML-Simple
DEPENDS+=		p5-XML-LibXSLT:../../textproc/p5-XML-LibXSLT
DEPENDS+=		p5-XML-Writer:../../textproc/p5-XML-Writer
DEPENDS+=		p5-XML-Writer-String:../../textproc/p5-XML-Writer-String
DEPENDS+=		p5-Business-ISSN:../../wip/p5-Business-ISSN
DEPENDS+=		p5-Business-ISMN:../../wip/p5-Business-ISMN

DEPENDS+=		p5-Readonly-XS:../../devel/p5-Readonly-XS
DEPENDS+=		tex-biblatex-1.7:../../print/tex-biblatex

DEPENDS+=		p5-IPC-Run3:../../devel/p5-IPC-Run3
DEPENDS+=		p5-Text-BibTeX:../../textproc/p5-Text-BibTeX
DEPENDS+=		p5-libwww:../../www/p5-libwww

BUILD_DEPENDS+=		p5-ExtUtils-LibBuilder>=0.4:../../devel/p5-ExtUtils-LibBuilder
BUILD_DEPENDS+=		p5-Config-AutoConf>=0.1:../../devel/p5-Config-AutoConf

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"


post-install:
		${INSTALL_PROGRAM_DIR} ${DESTDIR}${PREFIX}/bin
		${INSTALL_SCRIPT} ${WRKSRC:Q}/bin/biber ${DESTDIR}${PREFIX}/bin

