# $NetBSD: Makefile,v 1.30 2018/08/22 09:46:37 wiz Exp $

DISTNAME=	File-Remove-1.57
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	perl5 sysutils
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=File/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/File-Remove/
COMMENT=	Remove files and directories
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=	auto/File/Remove/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
