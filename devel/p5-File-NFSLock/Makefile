# $NetBSD: Makefile,v 1.25 2026/07/16 19:02:28 wiz Exp $

DISTNAME=	File-NFSLock-1.29
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	8
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=File/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/File-NFSLock
COMMENT=	NFS (or not) locking
LICENSE=	gnu-gpl-v2 OR artistic

PERL5_PACKLIST=		auto/File/NFSLock/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
