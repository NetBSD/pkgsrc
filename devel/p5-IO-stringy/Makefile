# $NetBSD: Makefile,v 1.22 2006/03/04 21:29:22 jlam Exp $
#

DISTNAME=	IO-stringy-2.109
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5isr
PKGREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=IO/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.zeegee.com/code/perl/IO-stringy/
COMMENT=	Perl class for I/O on in-core objects like strings and arrays

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/IO-stringy/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
