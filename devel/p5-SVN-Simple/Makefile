# $NetBSD: Makefile,v 1.2 2004/09/28 18:26:21 epg Exp $

DISTNAME=	SVN-Simple-0.25
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=OurNet/CLKAO/}

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	Simple interface to the Subversion delta editor interface

DEPENDS+=	p5-subversion>=1.0.4:../../devel/p5-subversion

USE_BUILDLINK3=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/SVN/Simple/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
