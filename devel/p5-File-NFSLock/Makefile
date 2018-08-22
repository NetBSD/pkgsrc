# $NetBSD: Makefile,v 1.15 2018/08/22 09:44:01 wiz Exp $

DISTNAME=	File-NFSLock-1.27
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	4
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=File/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/File-NFSLock/
COMMENT=	NFS (or not) locking
LICENSE=	gnu-gpl-v2 OR artistic

PERL5_PACKLIST=		auto/File/NFSLock/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
