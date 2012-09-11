# $NetBSD: Makefile,v 1.10 2012/09/11 07:46:41 sno Exp $

DISTNAME=	UNIVERSAL-isa-1.20120726
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/C/CH/CHROMATIC/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/UNIVERSAL-isa/
COMMENT=	Hack around people calling UNIVERSAL::isa() as a function
LICENSE=	${PERL5_LICENSE}

BUILD_DEPENDS+=	p5-CGI-[0-9]*:../../www/p5-CGI

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/UNIVERSAL/isa/.packlist

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
