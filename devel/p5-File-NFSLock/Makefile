# $NetBSD: Makefile,v 1.16 2018/12/01 02:54:15 wen Exp $

DISTNAME=	File-NFSLock-1.29
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=File/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/File-NFSLock/
COMMENT=	NFS (or not) locking
LICENSE=	gnu-gpl-v2 OR artistic

PERL5_PACKLIST=		auto/File/NFSLock/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
