# $NetBSD: Makefile,v 1.12 2005/07/13 18:01:21 jlam Exp $

DISTNAME=	MLDBM-Sync-0.15
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5msy
PKGREVISION=	1
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=MLDBM/}

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	Perl5 module for safe concurrent access to MLDBM databases

DEPENDS+= 	p5-MLDBM-[0-9]*:../../databases/p5-MLDBM
DEPENDS+= 	p5-Digest-MD5-[0-9]*:../../security/p5-Digest-MD5

PERL5_PACKLIST=		auto/MLDBM/Sync/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
