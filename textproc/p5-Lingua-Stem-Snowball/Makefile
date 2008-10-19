# $NetBSD: Makefile,v 1.5 2008/10/19 19:18:55 he Exp $

DISTNAME=	Lingua-Stem-Snowball-0.941
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Lingua/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Lingua-Stem-Snowball/
COMMENT=	Lingua::Stem::Snowball - Perl interface to Snowball stemmers

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_MODULE_TYPE=	Module::Build
PERL5_REQD+=	5.8.0
PERL5_PACKLIST=	auto/Lingua/Stem/Snowball/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
