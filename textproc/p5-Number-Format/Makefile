# $NetBSD: Makefile,v 1.12 2011/08/14 15:14:05 obache Exp $
#

DISTNAME=		Number-Format-1.73
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		2
CATEGORIES=		textproc
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Number/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Number-Format/
COMMENT=		Perl extension for formatting numbers
LICENSE=		${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/Number/Format/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
