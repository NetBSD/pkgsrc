# $NetBSD: Makefile,v 1.5 2005/04/11 21:46:21 tv Exp $

DISTNAME=	MIME-Types-1.15
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	mail perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=MIME/}

MAINTAINER=	adrianp@NetBSD.org
HOMEPAGE=	http://perl.overmeer.net/mimetypes/
COMMENT=	Definition of MIME types

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/MIME/Types/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
