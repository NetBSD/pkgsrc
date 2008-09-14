# $NetBSD: Makefile,v 1.17 2008/09/14 19:07:46 he Exp $
#

DISTNAME=	Net-Z3950-0.51
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5nz3
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Net/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://perl.z3950.org/
#HOMEPAGE=	http://search.cpan.org/dist/Net-Z3950/
COMMENT=	Perl interface to the Z39.50 information retrieval protocol

PKG_DESTDIR_SUPPORT=	user-destdir

#DEPENDS+=	p5-MARC>=1.15:../../databases/p5-MARC
DEPENDS+=	p5-Event>=0.77:../../devel/p5-Event

PERL5_PACKLIST=		auto/Net/Z3950/.packlist

.include "../../lang/perl5/module.mk"
.include "../../net/yaz/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
