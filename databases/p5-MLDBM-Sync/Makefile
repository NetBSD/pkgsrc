# $NetBSD: Makefile,v 1.5 2002/10/20 23:35:11 seb Exp $

DISTNAME=	MLDBM-Sync-0.15
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5msy
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=MLDBM/}

MAINTAINER=	packages@netbsd.org
COMMENT=	perl5 module for safe concurrent access to MLDBM databases

DEPENDS+= 	p5-MLDBM-[0-9]*:../../databases/p5-MLDBM
DEPENDS+= 	p5-Digest-MD5-[0-9]*:../../security/p5-Digest-MD5

USE_BUILDLINK2=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/MLDBM/Sync/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
