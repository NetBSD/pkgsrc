# $NetBSD: Makefile,v 1.12 2017/06/05 14:24:37 ryoon Exp $

.include "../../sysutils/ups-nut/Makefile.common"

PKGNAME=		${DISTNAME:S/nut/p5-UPS-Nut/}
COMMENT=		Network UPS Tools perl binding
PKGREVISION=		7
CATEGORIES=		sysutils perl5
PATCHDIR=		${.CURDIR}/patches

WRKSRC=			${WRKDIR}/${DISTNAME}/scripts/perl

PERL5_PACKLIST=		auto/UPS/Nut/.packlist

pre-configure:
	${CP} ${FILESDIR}/Makefile.PL ${WRKSRC}

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
