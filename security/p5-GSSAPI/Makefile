# $NetBSD: Makefile,v 1.1.1.1 2006/05/15 11:57:14 markd Exp $
#

DISTNAME=	GSSAPI-0.21
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	security perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=LWP/AGROLMS/}

MAINTAINER=	markd@NetBSD.org
HOMEPAGE=	http://perlgssapi.sourceforge.net/
COMMENT=	Perl extension providing access to the GSSAPIv2 library

PERL5_PACKLIST=	auto/GSSAPI/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/krb5.buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
