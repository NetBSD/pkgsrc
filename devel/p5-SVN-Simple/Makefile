# $NetBSD: Makefile,v 1.26 2016/06/08 19:23:29 wiz Exp $

DISTNAME=	SVN-Simple-0.28
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	7
CATEGORIES=	devel perl5 scm
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=SVN/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/SVN-Simple/
COMMENT=	Simple interface to the Subversion delta editor interface
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-subversion>=1.0.4:../../devel/p5-subversion

PERL5_PACKLIST=		auto/SVN/Simple/Edit/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
