# $NetBSD: Makefile,v 1.4 2001/11/26 06:49:55 jlam Exp $

DISTNAME=		Test-Harness-1.26
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5tha
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Test/}

MAINTAINER=		shell@shellhung.org
COMMENT=		perl5 module for testing

USE_BUILDLINK_ONLY=	YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Test/Harness/.packlist

post-patch:
	@perl -pi.orig -e 'm.INSTALLDIRS.&&s,.,,sg' ${WRKSRC}/Makefile.PL

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../lang/perl5/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
