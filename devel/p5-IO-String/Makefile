# $NetBSD: Makefile,v 1.4 2003/06/02 01:20:29 jschauma Exp $
#

DISTNAME=	IO-String-1.02
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=IO/}

MAINTAINER=	tech-pkg@netbsd.org
COMMENT=	Perl module for I/O on in-core objects like strings and arrays

USE_BUILDLINK2=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/IO/String/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
