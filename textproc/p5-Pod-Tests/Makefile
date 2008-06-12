# $NetBSD: Makefile,v 1.3 2008/06/12 02:14:48 joerg Exp $

DISTNAME=		Pod-Tests-0.18
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		textproc perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Pod/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Pod-Tests/
COMMENT=		Perl5 module that extracts embedded tests and code examples from POD

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/Pod-Tests/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
