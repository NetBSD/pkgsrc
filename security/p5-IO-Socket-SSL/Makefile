# $NetBSD: Makefile,v 1.6 2003/05/25 02:20:25 heinz Exp $

DISTNAME=	IO-Socket-SSL-0.92
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5iss
CATEGORIES=	security net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=IO/}

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://search.cpan.org/author/BEHROOZI/IO-Socket-SSL/
COMMENT=	perl5 SSL socket interface class

DEPENDS+=	p5-Net-SSLeay-[0-9]*:../../security/p5-Net-SSLeay

USE_BUILDLINK2=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/IO/Socket/SSL/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
