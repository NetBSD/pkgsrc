# $NetBSD: Makefile,v 1.12 2002/05/16 21:28:23 mjl Exp $
#

DISTNAME=	Digest-MD5-2.20
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5md5
CATEGORIES=	security perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Digest/}

MAINTAINER=	packages@netbsd.org
COMMENT=	Perl5 extension interface for MD5 algorithm

CONFLICTS+=	p5-MD5-[0-9]*

USE_BUILDLINK_ONLY=	YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Digest/MD5/.packlist

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../lang/perl5/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
