# $NetBSD: Makefile,v 1.1.1.1 2009/12/05 20:56:08 seb Exp $
#

DISTNAME=	Locale-Msgfmt-0.14
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Module/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Locale-Msgfmt/
COMMENT=	Perl 5 module to compile .po files to .mo files

USE_LANGUAGES=		# empty
PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=	auto/Locale/Msgfmt/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
