# $NetBSD: Makefile,v 1.17 2020/05/10 14:13:46 rillig Exp $
#

DISTNAME=	Authen-PAM-0.16
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	12
CATEGORIES=	security
MASTER_SITES=	http://search.cpan.org/CPAN/authors/id/N/NI/NIKIP/

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
