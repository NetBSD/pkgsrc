# $NetBSD: Makefile,v 1.7 2003/07/17 21:32:51 grant Exp $

DISTNAME=	Test-Cmd-1.04
PKGNAME=        p5-${DISTNAME}
SVR4_PKGNAME=	p5tcm
CATEGORIES=	devel perl5
MASTER_SITES=	http://www.baldmt.com/Test-Cmd/

MAINTAINER=	wulf@NetBSD.org
HOMEPAGE=	http://www.baldmt.com/Test-Cmd/
COMMENT=	perl5 module for testing of external commands and scripts

USE_BUILDLINK2=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Test/Cmd/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
