# $NetBSD: Makefile,v 1.1.1.1 2001/09/27 07:42:05 jlam Exp $

DISTNAME=	IO-Socket-SSL-0.80
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	security net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=IO/}

MAINTAINER=	packages@netbsd.org
COMMENT=	perl5 SSL socket interface class

DEPENDS+=	p5-Net-SSLeay-[0-9]*:../../security/p5-Net-SSLeay

USE_PERL5=	# defined
PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/IO/Socket/SSL/.packlist

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../mk/bsd.pkg.mk"
