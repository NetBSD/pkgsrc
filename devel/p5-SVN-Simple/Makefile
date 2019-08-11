# $NetBSD: Makefile,v 1.30 2019/08/11 13:20:17 wiz Exp $

DISTNAME=	SVN-Simple-0.28
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	10
CATEGORIES=	devel perl5 scm
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=SVN/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/SVN-Simple
COMMENT=	Simple interface to the Subversion delta editor interface
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-subversion>=1.0.4:../../devel/p5-subversion

PERL5_PACKLIST=		auto/SVN/Simple/Edit/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
