# $NetBSD: Makefile,v 1.5 2003/12/30 17:27:31 cjep Exp $
#

DISTNAME=	Net-Z3950-0.32
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5nz3
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Net/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://perl.z3950.org/
COMMENT=	Perl interface to the Z39.50 information retrieval protocol

DEPENDS+=	p5-MARC>=1.15:../../databases/p5-MARC
DEPENDS+=	p5-Event>=0.77:../../devel/p5-Event

USE_BUILDLINK2=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Net/Z3950/.packlist

.include "../../lang/perl5/module.mk"
.include "../../net/yaz/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
