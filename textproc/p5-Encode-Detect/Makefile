# $NetBSD: Makefile,v 1.27 2023/07/06 09:41:36 wiz Exp $
#

DISTNAME=		Encode-Detect-1.01
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		15
CATEGORIES=		textproc perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Encode/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://metacpan.org/release/Encode-Detect
COMMENT=		Perl module that detects the encoding of data
LICENSE=		mpl-1.1

#TOOL_DEPENDS+=		{perl>=5.9.3,p5-ExtUtils-CBuilder-[0-9]*}:../../devel/p5-ExtUtils-CBuilder

USE_LANGUAGES+=		c c++

PERL5_PACKLIST=		auto/Encode/Detect/.packlist
PERL5_MODULE_TYPE=	Module::Build

# https://rt.cpan.org/Public/Bug/Display.html?id=132207
SUBST_CLASSES+=		char
SUBST_STAGE.char=	pre-configure
SUBST_MESSAGE.char=	Fixing 'char array subscript' errors.
SUBST_FILES.char=	src/JpCntx.* src/nsSBCharSetProber.h src/Lang*Model.cpp
SUBST_SED.char=		-e 's,^extern \(char jp2CharContext\),extern unsigned \1,'
SUBST_SED.char+=	-e 's,^char jp2CharContext,unsigned &,'
SUBST_SED.char+=	-e 's,^  char \*precedenceMatrix,  unsigned &,'
SUBST_SED.char+=	-e 's,^char [[:alnum:]]*LangModel,unsigned &,'

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
