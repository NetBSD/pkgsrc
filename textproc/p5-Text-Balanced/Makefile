# $NetBSD: Makefile,v 1.18 2008/02/07 21:13:57 heinz Exp $
#

DISTNAME=	Text-Balanced-v2.0.0
PKGNAME=	p5-${DISTNAME:S/-v2/-2/1}
SVR4_PKGNAME=	p5tba
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Text/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Text-Balanced/
COMMENT=	Extract delimited text sequences from strings

PKG_DESTDIR_SUPPORT=	user-destdir
PKG_INSTALLATION_TYPES=	overwrite pkgviews

DEPENDS+=	p5-version-[0-9]*:../../devel/p5-version

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Text/Balanced/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
