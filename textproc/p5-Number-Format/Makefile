# $NetBSD: Makefile,v 1.7 2009/01/11 15:43:16 he Exp $
#

DISTNAME=		Number-Format-1.61a
PKGNAME=		p5-${DISTNAME:C/61a/61/}
CATEGORIES=		textproc
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Number/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Number-Format/
COMMENT=		Perl extension for formatting numbers

# Someone messed up 1.61, re-published?
WRKSRC=			${WRKDIR}/${DISTNAME:C/61a/61/}

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/Number/Format/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
