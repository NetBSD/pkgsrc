# $NetBSD: Makefile,v 1.20 2003/11/27 16:32:58 grant Exp $
#

DISTNAME=	Digest-MD5-2.30
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5md5
CATEGORIES=	security perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Digest/}

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	Perl5 extension interface for MD5 algorithm

CONFLICTS+=	p5-MD5-[0-9]*

USE_BUILDLINK2=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Digest/MD5/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
