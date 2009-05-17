# $NetBSD: Makefile,v 1.9 2009/05/17 10:15:41 sno Exp $
#

DISTNAME=		Number-Format-1.72a
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		textproc
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Number/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Number-Format/
COMMENT=		Perl extension for formatting numbers
LICENSE=		gnu-gpl-v2 # OR artistic

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/Number/Format/.packlist

WRKSRC=			${WRKDIR}/${DISTNAME:S/72a/72/}

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
