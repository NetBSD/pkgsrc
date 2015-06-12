# $NetBSD: Makefile,v 1.9 2015/06/12 10:49:09 wiz Exp $

DISTNAME=	Devel-Trace-0.12
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	4
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Devel/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Devel-Trace/
COMMENT=	Print out each line before it is executed (like sh -x)
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Devel/Trace/.packlist

pre-install:
	${FIND} ${WRKSRC} -name demo.pl | ${XARGS} ${CHMOD} -x

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
