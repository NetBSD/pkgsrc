# $NetBSD: Makefile,v 1.3 2002/08/20 15:52:11 abs Exp $

DISTNAME=		Text-Substitute-0.14
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		www perl5
MASTER_SITES=		http://www.mono.org/abs/tools/Text-Substitute/

MAINTAINER=		abs@netbsd.org
HOMEPAGE=		http://www.mono.org/abs/tools/Text-Substitute/
COMMENT=		perl5 module for text substition from hashes

USE_BUILDLINK_ONLY=	YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Text/Substitute/.packlist

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../lang/perl5/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
