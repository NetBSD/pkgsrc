# $NetBSD: Makefile,v 1.1.1.1 2002/10/19 17:01:23 dmcmahill Exp $
#

DISTNAME=	gettext-1.01
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5gtx
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Locale/}

MAINTAINER=	packages@netbsd.org
COMMENT=	perl5 module interface to C I18N functions

USE_BUILDLINK2=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Locale/gettext/.packlist

.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
