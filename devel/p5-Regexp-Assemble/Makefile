# $NetBSD: Makefile,v 1.2 2008/06/12 02:14:25 joerg Exp $
#

DISTNAME=	Regexp-Assemble-0.28
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Regexp/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Regexp-Assemble/
COMMENT=	Perl 5 module to assemble multiple regular expressions

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Regexp/Assemble/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
