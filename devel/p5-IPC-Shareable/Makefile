# $NetBSD: Makefile,v 1.36 2023/12/17 03:41:36 mef Exp $

DISTNAME=	IPC-Shareable-1.13
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=IPC/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/IPC-Shareable
COMMENT=	Tie a variable to shared memory
LICENSE=	gnu-gpl-v2

DEPENDS+=	p5-String-CRC32>=0:../../textproc/p5-String-CRC32

PERL5_PACKLIST=		auto/IPC/Shareable/.packlist

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD"
# The tests hang on NetBSD 9.2, both as unprivileged user and as root.
# The last words are:
#
# t/25ipc.......Could not create semaphore set: No space left on device
#   at t/25ipc.t line 37
TEST_TARGET=	# disabled
.endif

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
