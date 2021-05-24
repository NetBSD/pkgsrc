# $NetBSD: Makefile,v 1.18 2021/05/24 19:54:16 wiz Exp $

DISTNAME=	IO-KQueue-0.39
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	sysutils perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=IO/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/IO-KQueue
COMMENT=	Perl interface to the BSD kqueue system call
LICENSE=	${PERL5_LICENSE}

BUILD_DEPENDS+=	p5-perl-headers-[0-9]*:../../devel/p5-perl-headers
DEPENDS+=	p5-Devel-CheckLib-[0-9]*:../../devel/p5-Devel-CheckLib

.include "../../mk/bsd.prefs.mk"

.if !defined(PKG_HAVE_KQUEUE)
PKG_FAIL_REASON+=	"Requires kqueue(2)"
.endif

PERL5_PACKLIST=		auto/IO/KQueue/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
