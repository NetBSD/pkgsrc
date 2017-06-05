# $NetBSD: Makefile,v 1.11 2017/06/05 14:24:36 ryoon Exp $

DISTNAME=	IO-KQueue-0.34
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	8
CATEGORIES=	sysutils perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=IO/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/IO-KQueue/
COMMENT=	Perl interface to the BSD kqueue system call
LICENSE=	${PERL5_LICENSE}

BUILD_DEPENDS+=	p5-perl-headers-[0-9]*:../../devel/p5-perl-headers

ONLY_FOR_PLATFORM=	FreeBSD-*-* NetBSD-*-* OpenBSD-*-* DragonFly-*-* Darwin-*-*

PERL5_PACKLIST=		auto/IO/KQueue/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
