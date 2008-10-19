# $NetBSD: Makefile,v 1.10 2008/10/19 19:18:20 he Exp $

DISTNAME=	MIME-Types-1.24
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	mail perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=MIME/}

MAINTAINER=	adrianp@NetBSD.org
HOMEPAGE=	http://perl.overmeer.net/mimetypes/
COMMENT=	Definition of MIME types

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/MIME/Types/.packlist

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
