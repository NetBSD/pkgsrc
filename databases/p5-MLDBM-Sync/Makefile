# $NetBSD: Makefile,v 1.21 2011/10/17 03:14:52 hiramatsu Exp $

DISTNAME=	MLDBM-Sync-0.30
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
SVR4_PKGNAME=	p5msy
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=MLDBM/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/MLDBM-Sync/
COMMENT=	Perl5 module for safe concurrent access to MLDBM databases
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-MLDBM>=1:../../databases/p5-MLDBM
DEPENDS+=	p5-Digest-MD5-[0-9]*:../../security/p5-Digest-MD5

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/MLDBM/Sync/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
