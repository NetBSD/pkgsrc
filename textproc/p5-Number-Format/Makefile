# $NetBSD: Makefile,v 1.4 2008/06/12 02:14:48 joerg Exp $
#

DISTNAME=		Number-Format-1.52
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		textproc
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Number/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/~wrw/Number-Format/
COMMENT=		Perl extension for formatting numbers

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/Number/Format/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
