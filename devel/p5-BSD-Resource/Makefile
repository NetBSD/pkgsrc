# $NetBSD: Makefile,v 1.19 2006/10/14 08:02:37 wiz Exp $

DISTNAME=	BSD-Resource-1.24
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5bsd
PKGREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=BSD/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://users.tkk.fi/~jhi/
COMMENT=	Perl interface to BSD process resources library

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=	auto/BSD/Resource/.packlist

post-extract:
	${RM} -f ${WRKSRC}/t/[gs]etpriority.t

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
