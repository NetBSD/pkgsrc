# $NetBSD: Makefile,v 1.6 2003/02/12 18:28:51 wiz Exp $
#

DISTNAME=	ControlX10-CM11-2.09
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5cx1
CATEGORIES=	misc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=ControlX10/}

MAINTAINER=	damon@brodiefamily.org
HOMEPAGE=	http://members.aol.com/Bbirthisel/alpha.html
COMMENT=	perl5 module for controlling the X10 CM11A controller

DEPENDS+=	p5-Device-SerialPort>=0.07:../../comms/p5-Device-SerialPort

USE_BUILDLINK2=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/ControlX10/CM11/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
