# $NetBSD: Makefile,v 1.3 2004/11/02 22:50:27 seb Exp $
#

DISTNAME=	Unicode-String-2.07
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	converters
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Unicode/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.unicode.org/
COMMENT=	Perl5 modules to handle various Unicode issues

DEPENDS+=	p5-MIME-Base64-[0-9]*:../../converters/p5-MIME-Base64

USE_BUILDLINK3=		yes
PERL5_PACKLIST=         ${PERL5_SITEARCH}/auto/Unicode/String/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
