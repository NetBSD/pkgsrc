# $NetBSD: Makefile,v 1.1.1.1 2004/12/25 03:30:29 jlam Exp $

DISTNAME=      		Spiffy-0.21
PKGNAME=       		p5-${DISTNAME}
CATEGORIES=		www perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN}
CPAN_MODULE_DIR=	authors/id/I/IN/INGY

MAINTAINER=	jlam@NetBSD.org
COMMENT=	Object-oriented Perl framework

USE_BUILDLINK3=	yes
PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/Spiffy/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
