# $NetBSD: Makefile,v 1.1.1.1 2002/06/20 01:07:10 grant Exp $
#

DISTNAME=	Net-Goofey-1.5
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	chat perl5
MASTER_SITES=	http://tertius.net.au/~gossamer/code/Net-Goofey/

MAINTAINER=	grant@netbsd.org
HOMEPAGE=	http://tertius.net.au/~gossamer/code/
COMMENT=	perl module for communicating with a Goofey server

USE_BUILDLINK_ONLY=	YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Net/Goofey/.packlist

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../lang/perl5/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
