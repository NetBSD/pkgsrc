# $NetBSD: Makefile,v 1.3 2001/11/26 06:50:03 jlam Exp $

DISTNAME=		MIME-Lite-2.111
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5mil
CATEGORIES=		www perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=HTML/}

MAINTAINER=		norm@sandbox.org.uk
COMMENT=		perl5 module for simple creation of MIME email messages

USE_BUILDLINK_ONLY=	YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/MIME/Lite/.packlist

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../lang/perl5/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
