# $NetBSD: Makefile,v 1.1.1.1.2.2 2002/06/23 18:45:53 jlam Exp $
#

DISTNAME=	Font-TTF-0.28
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Font/}

MAINTAINER=	packages@netbsd.org
COMMENT=	Perl module for TrueType font hacking

USE_BUILDLINK_ONLY=	YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Font/TTF/.packlist

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../lang/perl5/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
