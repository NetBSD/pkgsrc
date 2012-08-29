# $NetBSD: Makefile,v 1.19 2012/08/29 13:58:08 wen Exp $
#

DISTNAME=	Font-TTF-1.00
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Font/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/~mhosken/Font-TTF/
COMMENT=	Perl module for TrueType font hacking
LICENSE=	artistic-2.0

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/${DISTNAME:S/.1//}

PERL5_PACKLIST=		auto/Font/TTF/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
