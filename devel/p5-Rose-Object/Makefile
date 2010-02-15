# $NetBSD: Makefile,v 1.10 2010/02/15 17:58:29 sno Exp $

DISTNAME=	Rose-Object-0.858
PKGNAME=	p5-${DISTNAME:S/854/85.4/}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Rose/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Rose-Object/
COMMENT=	Very simple class base class used by Rose objects
LICENSE=	${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/Rose/Object/.packlist

post-extract:
	${FIND} ${WRKSRC} -name "*.pm" -type f -exec ${CHMOD} -x {} \;

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
