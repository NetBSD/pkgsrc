# $NetBSD: Makefile,v 1.19 2013/05/31 12:39:46 wiz Exp $

DISTNAME=	Unicode-String-2.09
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	5
CATEGORIES=	converters perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Unicode/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Unicode-String/
COMMENT=	Perl5 modules to handle various Unicode issues
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-MIME-Base64-[0-9]*:../../converters/p5-MIME-Base64

PERL5_PACKLIST=		auto/Unicode/String/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
