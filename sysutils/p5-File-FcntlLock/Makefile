# $NetBSD: Makefile,v 1.1 2023/11/16 08:54:16 adam Exp $

DISTNAME=	File-FcntlLock-0.22
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	sysutils perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/J/JT/JTT/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/dist/File-FcntlLock
COMMENT=	File locking with fcntl(2)
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=	auto/File/FcntlLock/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
