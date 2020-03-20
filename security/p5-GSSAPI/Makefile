# $NetBSD: Makefile,v 1.20 2020/03/20 11:58:18 nia Exp $
#

DISTNAME=	GSSAPI-0.28
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	10
CATEGORIES=	security perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=LWP/AGROLMS/}

MAINTAINER=	markd@NetBSD.org
HOMEPAGE=	http://perlgssapi.sourceforge.net/
COMMENT=	Perl extension providing access to the GSSAPIv2 library
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=	auto/GSSAPI/.packlist
MAKE_PARAMS+=	--gssapiimpl=${KRB5BASE}

.include "../../lang/perl5/module.mk"
.include "../../mk/krb5.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
