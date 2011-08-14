# $NetBSD: Makefile,v 1.17 2011/08/14 12:43:26 obache Exp $
#

DISTNAME=	Font-TTF-0.45
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Font/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/~mhosken/Font-TTF/
COMMENT=	Perl module for TrueType font hacking

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/${DISTNAME:S/.1//}

PERL5_PACKLIST=		auto/Font/TTF/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
