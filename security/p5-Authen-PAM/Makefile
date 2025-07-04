# $NetBSD: Makefile,v 1.24 2025/07/04 08:47:55 wiz Exp $
#

DISTNAME=	Authen-PAM-0.16
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	18
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/N/NI/NIKIP/}

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://nik.pelov.name/Authen-PAM/
COMMENT=	Authentication via PAM

GNU_CONFIGURE=	yes
PERL5_PACKLIST=	auto/Authen/PAM/.packlist
USE_LANGUAGES=	c
USE_TOOLS+=	perl

.include "../../mk/pam.buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
