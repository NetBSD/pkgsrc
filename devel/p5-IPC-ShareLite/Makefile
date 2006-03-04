# $NetBSD: Makefile,v 1.13 2006/03/04 21:29:22 jlam Exp $
#

DISTNAME=	IPC-ShareLite-0.09
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=IPC/}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Light-weight interface to shared memory

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		auto/IPC/ShareLite/.packlist

post-extract:
	cd ${WRKSRC} && ${MV} -f sharelite.c ipcsharelite.c

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"

# ensure this is at the end of MAKE_PARAMS
MAKE_PARAMS+=	</dev/null
