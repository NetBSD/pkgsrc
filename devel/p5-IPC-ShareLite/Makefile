# $NetBSD: Makefile,v 1.9 2005/03/22 07:37:05 schmonz Exp $
#

DISTNAME=	IPC-ShareLite-0.09
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=IPC/}

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	Light-weight interface to shared memory

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=		 YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/IPC/ShareLite/.packlist

post-extract:
	cd ${WRKSRC} && ${MV} -f sharelite.c ipcsharelite.c

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"

# ensure this is at the end of MAKE_PARAMS
MAKE_PARAMS+=	</dev/null
