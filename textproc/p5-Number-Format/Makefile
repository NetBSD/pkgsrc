# $NetBSD: Makefile,v 1.11 2010/08/21 16:35:55 seb Exp $
#

DISTNAME=		Number-Format-1.73
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		1
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
