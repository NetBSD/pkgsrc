# $NetBSD: Makefile,v 1.18 2011/08/16 21:48:05 wiz Exp $
#

DISTNAME=	Font-TTF-0.48
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
