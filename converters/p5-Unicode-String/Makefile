# $NetBSD: Makefile,v 1.12 2007/02/27 13:48:05 wiz Exp $
#

DISTNAME=	Unicode-String-2.09
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	converters perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Unicode/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Unicode-String/
COMMENT=	Perl5 modules to handle various Unicode issues

DEPENDS+=	p5-MIME-Base64-[0-9]*:../../converters/p5-MIME-Base64

PERL5_PACKLIST=		auto/Unicode/String/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
