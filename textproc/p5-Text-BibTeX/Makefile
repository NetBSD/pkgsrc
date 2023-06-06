# $NetBSD: Makefile,v 1.60 2023/06/06 12:42:29 riastradh Exp $

DISTNAME=	Text-BibTeX-0.89
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Text/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.gerg.ca/software/btOOL/
#HOMEPAGE=	http://search.cpan.org/dist/Text-BibTeX/
COMMENT=	Perl library for reading, parsing, and processing BibTeX files
LICENSE=	${PERL5_LICENSE}

TOOL_DEPENDS+=		p5-Capture-Tiny>=0.06:../../devel/p5-Capture-Tiny
TOOL_DEPENDS+=		p5-Config-AutoConf>=0.320:../../devel/p5-Config-AutoConf
TOOL_DEPENDS+=		p5-ExtUtils-LibBuilder>=0.01:../../devel/p5-ExtUtils-LibBuilder
#TOOL_DEPENDS+=	{perl>=5.14.1,p5-ExtUtils-CBuilder>=0.27}:../../devel/p5-ExtUtils-CBuilder

USE_LANGUAGES+=		c c99
PERL5_PACKLIST=		auto/Text/BibTeX/.packlist
PERL5_MODULE_TYPE=	Module::Build

ALL_ENV+=	TMPDIR=${WRKDIR}/tmp

pre-configure:
	${MKDIR} ${WRKDIR}/tmp

.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} == "Darwin"
post-build:
.  for f in bin/biblex bin/bibparse bin/dumpnames usrlib/libbtparse.dylib
	${CHMOD} u+w ${WRKSRC}/blib/${f}
.  endfor
.endif

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
