# $NetBSD: Makefile,v 1.29 2019/08/11 13:19:40 wiz Exp $

DISTNAME=	IPC-Shareable-0.61
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	5
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=IPC/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/IPC-Shareable
COMMENT=	Tie a variable to shared memory
LICENSE=	gnu-gpl-v2

#DEPENDS+=	p5-Storable>=1.0.14:../../devel/p5-Storable

PERL5_PACKLIST=		auto/IPC/Shareable/.packlist

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD"
# The tests hang on NetBSD 3.0, both as unprivileged user and as root.
# The last words are:
#
# t/25ipc.......Could not create semaphore set: No space left on device
#   at t/25ipc.t line 37
TEST_TARGET=	# disabled
.endif

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
