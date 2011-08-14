# $NetBSD: Makefile,v 1.20 2011/08/14 08:18:09 obache Exp $

DISTNAME=	MLDBM-Sync-0.30
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
SVR4_PKGNAME=	p5msy
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=MLDBM/}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Perl5 module for safe concurrent access to MLDBM databases

DEPENDS+=	p5-MLDBM>=1:../../databases/p5-MLDBM
DEPENDS+=	p5-Digest-MD5-[0-9]*:../../security/p5-Digest-MD5

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/MLDBM/Sync/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
