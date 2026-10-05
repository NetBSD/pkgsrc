# $NetBSD: Makefile,v 1.40 2026/10/05 02:19:49 wen Exp $

DISTNAME=	IPC-Shareable-1.19
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/S/ST/STEVEB/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/IPC-Shareable
COMMENT=	Tie a variable to shared memory
LICENSE=	gnu-gpl-v2

EXTRACT_USING=	gtar

DEPENDS+=	p5-String-CRC32>=0:../../textproc/p5-String-CRC32

PERL5_PACKLIST=		auto/IPC/Shareable/.packlist

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD"
# The tests failed on NetBSD, because: 
# 'sysv_info() returns undef on unsupported platform (netbsd)'
#
TEST_TARGET=	# disabled
.endif

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
