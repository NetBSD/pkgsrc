# $NetBSD: Makefile,v 1.4 2008/10/19 19:18:46 he Exp $
#

DISTNAME=	GSSAPI-0.26
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	security perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=LWP/AGROLMS/}

MAINTAINER=	markd@NetBSD.org
HOMEPAGE=	http://perlgssapi.sourceforge.net/
COMMENT=	Perl extension providing access to the GSSAPIv2 library

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=	auto/GSSAPI/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/krb5.buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
