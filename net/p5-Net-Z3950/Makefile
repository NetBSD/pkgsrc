# $NetBSD: Makefile,v 1.12 2006/02/05 23:10:28 joerg Exp $
#

DISTNAME=	Net-Z3950-0.32
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	4
SVR4_PKGNAME=	p5nz3
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Net/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://perl.z3950.org/
COMMENT=	Perl interface to the Z39.50 information retrieval protocol

DEPENDS+=	p5-MARC>=1.15:../../databases/p5-MARC
DEPENDS+=	p5-Event>=0.77:../../devel/p5-Event

PERL5_PACKLIST=		auto/Net/Z3950/.packlist

.include "../../lang/perl5/module.mk"
.include "../../net/yaz/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
