# $NetBSD: Makefile,v 1.4 2003/06/02 01:20:27 jschauma Exp $
#

DISTNAME=	IPC-ShareLite-0.08
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=IPC/}

MAINTAINER=	tech-pkg@netbsd.org
COMMENT=	Light-weight interface to shared memory

USE_BUILDLINK2=		 YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/IPC/ShareLite/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"

# ensure this is at the end of MAKE_PARAMS
MAKE_PARAMS+=	</dev/null
