# $NetBSD: Makefile,v 1.1.1.1.2.1 2002/06/23 18:41:01 jlam Exp $
#

DISTNAME=	Net-AIM-1.22
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	chat perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Net/}

MAINTAINER=	schmonz@netbsd.org
HOMEPAGE=	http://www.aryeh.net/Net-AIM/
COMMENT=	implementation of the AOL Instant Messenger TOC protocol

USE_BUILDLINK_ONLY=	YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Net/AIM/.packlist

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../lang/perl5/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
