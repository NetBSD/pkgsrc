# $NetBSD: Makefile,v 1.9 2010/02/02 19:26:25 sno Exp $

DISTNAME=	Lingua-EN-Inflect-1.891
PKGNAME=	p5-${DISTNAME:S/891/89.1/}
#PKGREVISION=	1
SVR4_PKGNAME=	p5lei
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Lingua/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Lingua-EN-Inflect/
COMMENT=	Perl module for inflection of english words and a/an selection
LICENSE=	${PERL5_LICENSE}

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

REPLACE_PERL+=	demo*.pl

PERL5_PACKLIST=	auto/Lingua/EN/Inflect/.packlist
PERL5_MODULE_TYPE=	Module::Build

post-extract:
	${MV} ${WRKSRC}/Build.pl ${WRKSRC}/Build.PL

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
