# $NetBSD: Makefile,v 1.5 2003/07/17 21:32:57 grant Exp $
#

DISTNAME=	gettext-1.01
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5gtx
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Locale/}

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	perl5 module interface to C I18N functions

USE_BUILDLINK2=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Locale/gettext/.packlist

.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
