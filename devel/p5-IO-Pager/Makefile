# $NetBSD: Makefile,v 1.24 2019/08/11 13:19:38 wiz Exp $
#

DISTNAME=	IO-Pager-0.40
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=IO/}
EXTRACT_SUFX=  .tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/IO-Pager
COMMENT=	Perl module for paged I/O to the terminal
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-File-Which-[0-9]*:../../devel/p5-File-Which

WRKSRC=		${WRKDIR}/IO-Pager-0.4

PERL5_PACKLIST=		auto/IO/Pager/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
