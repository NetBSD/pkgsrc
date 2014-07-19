# $NetBSD: Makefile,v 1.9 2014/07/19 14:26:07 wiz Exp $

DISTNAME=		Convert-Translit-1.03
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		5
CATEGORIES=		converters perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Convert/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Convert-Translit/
COMMENT=		Perl5 module to transliterate various character sets

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Convert/Translit/.packlist
REPLACE_PERL=		lib/Convert/Translit.pm

SUBST_CLASSES=		example
SUBST_FILES.example=	MANIFEST
SUBST_SED.example=	-e "s@^example\.pl@@"
SUBST_STAGE.example=	post-extract

post-extract:
	${RM} -f ${WRKSRC}/example.pl

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
