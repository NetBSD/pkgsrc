# $NetBSD: Makefile,v 1.10 2005/04/11 21:45:32 tv Exp $
#

DISTNAME=	IPC-ShareLite-0.09
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=IPC/}

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	Light-weight interface to shared memory

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/IPC/ShareLite/.packlist

post-extract:
	cd ${WRKSRC} && ${MV} -f sharelite.c ipcsharelite.c

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"

# ensure this is at the end of MAKE_PARAMS
MAKE_PARAMS+=	</dev/null
