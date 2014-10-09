# $NetBSD: Makefile,v 1.24 2014/10/09 14:06:58 wiz Exp $

DISTNAME=	File-Remove-1.52
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	perl5 sysutils
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=File/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/File-Remove/
COMMENT=	Remove files and directories
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=	auto/File/Remove/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
