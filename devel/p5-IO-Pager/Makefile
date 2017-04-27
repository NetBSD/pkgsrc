# $NetBSD: Makefile,v 1.18 2017/04/27 13:12:06 mef Exp $
#

DISTNAME=	IO-Pager-0.37
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=IO/}
EXTRACT_SUFX=  .tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/IO-Pager/
COMMENT=	Perl module for paged I/O to the terminal
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-File-Which-[0-9]*:../../devel/p5-File-Which

PERL5_PACKLIST=		auto/IO/Pager/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
