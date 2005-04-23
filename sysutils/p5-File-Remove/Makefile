# $NetBSD: Makefile,v 1.2 2005/04/23 17:31:05 adrianp Exp $

DISTNAME=	File-Remove-0.29
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	perl5 sysutils
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=File/}

MAINTAINER=	adrianp@NetBSD.org
HOMEPAGE=	http://search.cpan.org/~rsod/${DISTNAME}/
COMMENT=	Remove files and directories

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/File/Remove/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
