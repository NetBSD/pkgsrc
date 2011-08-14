# $NetBSD: Makefile,v 1.3 2011/08/14 15:14:04 obache Exp $

DISTNAME=	Lingua-PT-Stemmer-0.01
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Lingua/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Lingua-PT-Stemmer/
COMMENT=	Perl5 modules for Galician and Portuguese language stemming
LICENSE=	${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=	auto/Lingua/PT/Stemmer/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
