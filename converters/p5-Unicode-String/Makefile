# $NetBSD: Makefile,v 1.6 2005/02/19 19:26:02 wiz Exp $
#

DISTNAME=	Unicode-String-2.07
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	converters perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Unicode/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Unicode-String/
COMMENT=	Perl5 modules to handle various Unicode issues

DEPENDS+=	p5-MIME-Base64-[0-9]*:../../converters/p5-MIME-Base64

USE_BUILDLINK3=		yes
PERL5_PACKLIST=         ${PERL5_SITEARCH}/auto/Unicode/String/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
