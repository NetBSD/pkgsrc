# $NetBSD: Makefile,v 1.1.1.1 2001/12/19 13:22:41 abs Exp $

DISTNAME=		Text-CSV-Hash-0.02
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		www perl5
MASTER_SITES=		http://www.mono.org/abs/tools/Text-CSV-Hash/

MAINTAINER=		abs@netbsd.org
HOMEPAGE=		http://www.mono.org/abs/tools/Text-CSV-Hash/
COMMENT=		perl5 module for hash based CSV usage

USE_BUILDLINK_ONLY=	YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Text/CSV/Hash/.packlist

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../lang/perl5/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
